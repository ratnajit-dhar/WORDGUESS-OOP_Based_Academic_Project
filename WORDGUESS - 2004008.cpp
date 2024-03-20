#include<bits/stdc++.h>
using namespace std;

class MainGame
{
public:
    static int total,correct;
    string mainword;
    MainGame(){
        total++;
    }
    static void show()
    {
        cout << "Total Words Learned: " << total << endl;
        cout << "Correct Guess: " << correct << endl;
        cout << "Wrong Guess: " << total-correct << endl;
    }
};

int MainGame :: total;
int MainGame :: correct;

class fiveletter : public MainGame
{
public:
    static int total5;
    fiveletter(string s){
        total5++;
        mainword=s;
    }
    template <class T>
    friend void CheckLoop(T x, int lp);
    static void showtot()
    {
        cout << "Total 5-letter word learned: " << total5 << endl;
    }
};

int fiveletter :: total5;

class sixletter : public MainGame
{
public:
    static int total6;
    sixletter(string s){
        total6++;
        mainword=s;
    }
    template <class T>
    friend void CheckLoop(T x, int lp);
    static void showtot()
    {
        cout << "Total 6-letter word learned: " << total6 << endl;
    }
};

int sixletter :: total6;

class sevenletter : public MainGame
{
public:
    static int total7;
    sevenletter(string s){
        total7++;
        mainword=s;
    }
    template <class T>
    friend void CheckLoop(T x, int lp);
    static void showtot()
    {
        cout << "Total 7-letter word learned: " << total7 << endl;
    }
};

int sevenletter :: total7;

template <class T>
void CheckLoop(T x, int lp)
{
    cout << "Start Guessing" << endl;
    bool check=false;
    for(int i=1;i<=6;i++){
        cout << "You have " << 6-i+1 << " guesses left" << endl;
        string guess;
        cin >> guess;
        int where=-1;
        for(int j=0;j<lp;j++){
            bool check=false;
            for(int k=0;k<lp;k++){
                if(guess[j]==x.mainword[k]){
                    if(j==k){
                        where=1;
                        check=true;
                        break;
                    }
                    else{
                        where=0;
                        check=true;
                    }
                }
            }
            if(check){
                if(where==0) cout << " Mis |";
                else if(where==1) cout << " Cor |";
            }
            else if(check!=true){
                cout << " Wro |";
            }
        }
        cout << endl;
        int cnt=0;
        for(int m=0,n=0;m<lp,n<lp;m++,n++){
            if(guess[m]==x.mainword[n]){
                cnt++;
            }
        }
        if(cnt==lp){
            MainGame :: correct++;
            cout << endl;
            cout << "Bingo! You have found the word." << endl;
            check=true;
            break;
        }
    }
    if(!check){
        cout << endl;
        cout << "Alas! You were unable to guess the word" << endl << endl;
        cout << "The correct word is: " << x.mainword << endl;
        cout << endl << endl << endl;;
    }
}


void menu()
{
    cout.width(60);
    cout << "WORDGUESS!" << endl << endl;
    cout.width(50);
    cout << "1. 5 letter word" << endl;
    cout.width(50);
    cout << "2. 6 letter word" << endl;
    cout.width(50);
    cout << "3. 7 letter word" << endl;
    cout.width(47);
    cout << "4. Statistics" << endl;
    cout.width(41);
    cout << "5. Exit" << endl;
}

void HowToPlay()
{
    cout << "1. First Select an option from three types of Challenge" << endl;
    cout << "2. You will get 6 tries to guess the word correctly" << endl;
    cout << "3. In each Try, you enter a word. The the game will check for each letter in the word" << endl;
    cout << "4. If a letter is present in the word and in correct place, | Cor | will be shown" << endl;
    cout << "5. If a letter is present in the word but not in the correct place, | Mis | will be shown" << endl;
    cout << "6. If a letter is not present in the word, | Wro | will be shown" << endl;
    cout << "7. Select Statistics to get a overview" << endl;
}

int main()
{
    srand(time(0));
    vector <string> list5,list6,list7;
    fstream outf1("Dictionary 5letter.txt");
    char ch;
    int cnt=0;
    string nw;
    while(outf1.get(ch)){
        if(ch=='\n') continue;
        nw.push_back(ch);
        cnt++;
        if(cnt==5){
            cnt=0;
            list5.push_back(nw);
            nw.clear();
        }
    }
    outf1.close();
    fstream outf2("Dictionary 6letter.txt");
    while(outf2.get(ch)){
        if(ch=='\n') continue;
        nw.push_back(ch);
        cnt++;
        if(cnt==6){
            cnt=0;
            list6.push_back(nw);
            nw.clear();
        }
    }
    outf2.close();
    fstream outf3("Dictionary 7letter.txt");
    while(outf3.get(ch)){
        if(ch=='\n') continue;
        nw.push_back(ch);
        cnt++;
        if(cnt==7){
            cnt=0;
            list7.push_back(nw);
            nw.clear();
        }
    }
    outf3.close();
    // cout << list5.size() << endl;
    // cout << list6.size() << endl;
    // cout << list7.size() << endl;
    vector <string> WordsLearned;
    cout.width(60);
    cout << "WORDGUESS" << endl << endl;
    cout.width(64);
    cout << "***HOW TO PLAY***" << endl << endl;
    HowToPlay();
    cout << "Enter any key to begin" << endl;
    char start;
    if(cin >> start) system("cls");
    while(1){
        menu();
        int option;
        cin >> option;
        if(option==5) break;
        else if(option==1){
            system("cls");
            int how=rand()%(list5.size());
            string mainword=list5[how];
            fiveletter start(mainword);
            WordsLearned.push_back(mainword);
            CheckLoop(start,5);
        }
        else if(option==2){
            system("cls");
            int how=rand()%(list6.size());
            string mainword=list6[how];
            sixletter start(mainword);
            WordsLearned.push_back(mainword);
            CheckLoop(start,6);
        }
        else if(option==3){
            system("cls");
            int how=rand()%(list7.size());
            string mainword=list7[how];
            sevenletter start(mainword);
            WordsLearned.push_back(mainword);
            CheckLoop(start,7);
        }
        else if(option==4){
            system("cls");
            MainGame :: show();
            fiveletter :: showtot();
            sixletter :: showtot();
            sevenletter :: showtot();
            sort(WordsLearned.begin(),WordsLearned.end());
            cout.width(20);
            cout << "Words Learned" << endl;
            cout.width(20);
            cout << "______________" << endl;
            for(int i=0;i<WordsLearned.size();i++){
                cout.width(15);
                cout << WordsLearned[i] << endl;
            }
        }
        cout << "Enter any key to continue" << endl;
        char cont;
        if(cin >> cont) system("cls");
    }
}
//iloveyouu
// iloveyoutoooo
