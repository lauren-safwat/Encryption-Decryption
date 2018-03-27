//FCI - Programming 1 - 2018 - Assignment 2
//Program name: Encryption program
//Last Modification Date: 1/3/2018
//Author 1 and ID and group: Lauren Safwat - 20170203 - Group 8
//Author 2 and ID and group: Kareem Magdy - 20170197 - Group 8
//Author 3 and ID and group: Mario Osama - 20170209 - Group 8
//Teaching Assistants: Mohamed Atta & Ibrahim Zidan
//Purpose: To encrypt or decrypt text

#include <iostream>
#include<string>
#include <cstring>


using namespace std;

void encrypt3(string x) //for Rail fence cipher
{
        for(int i=0; i<x.length();i++){
            if(x[i]==' '){
            x.erase(i,1);                        //first for loop to remove spaces
            }
        }
        for(int i=0; i<x.length(); i++){         //second one starts from first letter to print letter and leave 3 then print another
            cout<<x[i];
            i+=3;

        }
        for(int i=1; i<x.length();i++){          //third loop starts from second letter to print letter and leave 1 and so on
            cout<<x[i];
            i+=1;
        }
        for(int i=2; i<x.length(); i++){         //4th loop start from 3rd letter to print one and leave 3
            cout<<x[i];
            i+=3;
        }
                                                 // so we get the zigzag shape

}

void decrypt3(string y)  //for Rail fence cipher
{
    int k=0;
   string firstArray[y.length()] , secondArray[y.length()] , thirdArray[y.length()];
   for(int i=0; i<y.length(); i++){
        firstArray[i]=y[k];                      // made 3 arrays represent the 3 rows and no. of columns is word length
        i+=3; k++;
    }                                            // first loop add first char , leave 3 spaces , then add second and so on
    for(int i=1; i<y.length(); i++){
        secondArray[i]=y[k];
        i+=1; k++;                               // 2nd loop starts from index 2 , add the next char and leave one space
    }
    for(int i=2; i<y.length(); i++){
        thirdArray[i]=y[k];                      // 3rd loop starts from index 3 , add the next char and leave 3 spaces , thats how we get the zigzag shape
        i+=3; k++;
    }
    for(int i=0; i<y.length();i++){
        cout<<firstArray[i]<<secondArray[i]<<thirdArray[i];    //last loop print char vertically so we get them on the right order
    }
}

//for baconian cipher
string alpha1[]={" ","aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","","\0"};
char alpha[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
string letterM;
char baconian_english(const string&letter){
    if(letter.empty())
        return ' ';
    for(int i=0 ; i<26 ; i++){
        if(letterM == alpha1[i])
            return alpha[i];
    }
}

//for morse code
string morse[]={" ",".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","\0"};
string LetterM;
char morse_english(const string letter){
    if(letter.empty())
        return ' ';
    for(int i=0 ; i<26 ; i++){
        if(LetterM == morse[i])
            return alpha[i];
    }
}


int main()
{
    int choice1 , cipher , choice2;
    string text;
    char A[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','\0'};
    char B[]={'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    char C[]={'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','\0'};
    char D[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','\0'};
    char E[]={'n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    char F[]={'z','y','x','w','v','u','t','s','r','q','p','o','n','\0'};
    char G[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    char H[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    cout << endl << "\t\t\t\t\t\t\tWELCOME" << endl;

    while (true){
        cout << "To continue: press 1" << endl;
        cout << "To exit the program: press 2" << endl;
        cout << "Your choice is: ";
        cin >> choice1;

        if (choice1 == 1){
            cout << "\nWhich Cipher from the following do you want to use? \n   1-Affine Cipher \n   2-Caesar Cipher \n   3-Atbash Cipher \n   4-ROT13 Cipher \n   5-Baconian Cipher \n   6-Simple Substitution \n   7-Polybius Square Cipher \n   8-Morse Code \n   9-XOR Cipher \n   10-Rail Fence Cipher \n";
            cout << "Enter the number of your choice: ";
            cin >> cipher;
            cout << "\nWhat do you want to do? \n 1-Encryption \n 2-Decryption \n";
            cout << "Your choice is: ";
            cin >> choice2;

            if (cipher == 1){
                char alpha[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
                char encrypt[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
                char decrypt[]= {'a','b','c','d','e','f','g','h','i','j','k','l' ,'m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
                string sentence;
                string answer;
                int number=0;
                int a;
                int b;
                int c;
                int a_values[]={1,3,5,7,9,11,15,17,19,21,23,25};
                int c_values[]={1,9,21,15,3,19,7,23,11,5,17,25};

                if (choice2 == 1){
                    cout << "Enter an odd number(slope) from 1 to 25 (except 13): ";
                    cin >> a;

                    while((a<1||a>25)||a%2==0||a==13){
                        cout << "Invalid number enter a new one: ";
                        cin >> a;}

                    cout << "Enter the intercept(>0): ";
                    cin >> b;
                    while(b<=0){
                        cout << "Invalid number, enter a new one: ";
                        cin >> b; }

                    for(int i=0 ; i<sizeof(a_values) ; i++){
                        if(a==a_values[i]){
                            c=c_values[i];
                            break;}
                    }

                    for (int i=0 ; i<26 ; i++)
                        encrypt[i] = alpha[(i*a+b)%26];

                    cout << "\nEnter the message you want to encrypt: ";
                    cin.ignore();
                    getline(cin,sentence);
                    for(int x=0 ; x<sentence.length() ; x++){
                        for(int y=0 ; y<26 ; y++){
                            if(sentence[x] == alpha[y]){
                                sentence[x] = encrypt[y];
                                break;
                            }
                        }
                    }
                    cout << "Your message is: " << sentence << endl << endl;
                }
                else if (choice2 == 2){
                    cout << "Enter an odd number(slope) from 1 to 25 (except 13): ";
                    cin >> a;

                    while((a<1||a>25)||a%2==0||a==13){
                        cout << "Invalid number enter a new one: ";
                        cin >> a;}

                    cout << "Enter the intercept(>0): ";
                    cin >> b;
                    while(b<=0){
                        cout << "Invalid number, enter a new one: ";
                        cin >> b; }

                    for(int i=0 ; i<sizeof(a_values) ; i++){
                        if(a==a_values[i]){
                            c=c_values[i];
                            break;}
                    }
                    cout << "\nEnter the message you want to decrypt: ";
                    cin.ignore();
                    getline(cin,sentence);

                    for (int i=0 ; i<26 ; i++){
                        int g=0;
                        g=(c*(i-b))%26;
                        while(g<0)
                            g=g+26;
                        decrypt[i]=alpha[g];
                    }

                    for(int x=0 ; x<sentence.length() ; x++){
                        for(int y=0 ; y<26 ; y++){
                            if(sentence[x]==alpha[y]){
                                sentence[x]=decrypt[y];
                                break;
                            }
                        }
                    }

                    cout << "Your message is: " << sentence << endl << endl;
                }
            }

            else if (cipher == 2){
                int shift;
                if (choice2 == 1){
                    cout << "\nEnter the message you want to encrypt: ";
                    cin.ignore();
                    getline(cin,text);
                    cout << endl << "Enter the number of shifts: ";
                    cin >> shift;

                    for (int i=0 ; i < text.length() ; i++){
                        for (int j=0 ; j<26 ; j++){
                            if (j >= (26-shift)){
                                if (text[i] == G[j]){
                                    text[i] = G[j+shift-26];
                                    break;}
                                else if (text[i] == H[j]){
                                    text[i] = H[j+shift-26];
                                    break;}
                            }
                            else if (text[i] == G[j]){
                                text[i] = G[j+shift];
                                break;}
                            else if (text[i] == H[j]){
                                text[i] = H[j+shift];
                                break;}
                        }
                    }
                    cout << "Your message is: " << text << endl << endl;
                }
                else if (choice2 == 2){
                    cout << "\nEnter the message you want to decrypt: ";
                    cin.ignore();
                    getline(cin,text);
                    cout << endl << "Enter the number of shifts: ";
                    cin >> shift;

                    for (int i=0 ; i < text.length() ; i++){
                        for (int j=0 ; j<26 ; j++){
                            if (j < shift){
                                if (text[i] == G[j]){
                                    text[i] = G[j-shift+26];
                                    break;}
                                else if (text[i] == H[j]){
                                    text[i] = H[j-shift+26];
                                    break;}
                            }
                            else if (text[i] == G[j]){
                                text[i] = G[j-shift];
                                break;}
                            else if (text[i] == H[j]){
                                text[i] = H[j-shift];
                                break;}
                        }
                    }
                    cout << "Your message is: " << text << endl << endl;
                }
            }

            else if (cipher == 3){
                cout << "\nPlease, enter the message: ";
                cin.ignore();
                getline(cin,text);

                for (int i=0 ; i<text.length() ; i++){
                    for(int j=0 ; j<13 ; j++){
                        if (text[i] == A[j])
                            text[i] = C[j];
                        else if (text[i] == C[j])
                            text[i] = A[j];
                        else if (text[i] == D[j])
                            text[i] = F[j];
                        else if (text[i] == F[j])
                            text[i] = D[j];
                    }
                }

                cout << "\nYour message is: " << text << endl << endl;
            }

            else if (cipher == 4){
                cout << "\nPlease, enter the message: ";
                cin.ignore();
                getline(cin,text);

                for (int i=0 ; i<text.length() ; i++){
                    for(int j=0 ; j<13 ; j++){
                        if (text[i] == A[j])
                            text[i] = B[j];
                        else if (text[i] == B[j])
                            text[i] = A[j];
                        else if (text[i] == D[j])
                            text[i] = E[j];
                        else if (text[i] == E[j])
                            text[i] = D[j];
                    }
                }

                cout << "\nYour message is: " << text << endl << endl;
            }

            else if (cipher == 5){
                string code;
                string english;
                int counter=0;
                string space=" ";
                string sentence1;

                if (choice2 == 1){
                    cout << "\nEnter message required to encrypt : ";
                    cin.ignore();
                    getline(cin,sentence1);
                    for(int x=0 ; x<sentence1.length() ; x++){
                        for(int y=0 ; y<27 ; y++){
                            if(sentence1[x] == alpha[y])
                                cout << alpha1[y] << " ";
                            else{
                                for (int i=0 ; i<27 ; i++){
                                    if (sentence1[x] == alpha[i])
                                        counter++;}
                                if (counter==0){
                                    cout<<"invalid input the program will now terminate.";
                                    return 0;  }
                                }
                        }
                    }
                    cout << endl << endl;
                }
                else if (choice2 == 2){
                    cout<<"\nEnter message required to decrypt : ";
                    cin.ignore();
                    getline(cin,code);
                    code = code + ' ';
                    for(int i=0 ;i<code.length() ; i++){
                        int g,j;
                        g = i+1;
                        j = i+2;
                        if(code[i] == ' '){
                            if(code[g] == ' ' && code[j] == ' ')
                                cout<<" ";
                        english = english + baconian_english(letterM);
                        letterM.clear();
                        }
                    else{
                        letterM = letterM + code[i];
                        }
                    }
                    cout<<english<<endl;
                    english.clear();
                    cout << endl;
                }
            }

            else if (cipher == 6){
                string Key , sentence , result="";
                string encrypt="";
                char Alpha[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
                char Alpha1[]= {'a','b','c','d','e','f','g','h','i','j','k','l' ,'m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
                if (choice2 == 1){
                    cout << "Enter the key: ";
                    cin >> Key;
                    cout << "Enter the message you want to encrypt: ";
                    cin.ignore();
                    getline(cin,sentence);
                    for(int i=0 ; i<Key.length() ; i++)
                        encrypt = encrypt + Key[i];
                    for(int y=0 ; y<Key.length() ; y++){
                        for(int z=0 ; z<26 ; z++){
                            if(Key[y] == Alpha[z])
                                Alpha[z]='*';
                        }
                    }
                    for(int x=0 ; x<26 ; x++){
                        if(Alpha[x]=='*')
                            continue;
                        else{
                            encrypt = encrypt + Alpha[x];
                            }
                    }
                    for(int i=0 ; i<sentence.length() ; i++){
                        for(int x=0 ; x<26 ; x++){
                            if(sentence[i] == Alpha1[x])
                                result = result + encrypt[x];
                        }
                    }
                    cout << result << endl << endl;
                    result.clear();
                }
                else if (choice2 == 2){
                    cout << "Enter the key: ";
                    cin >> Key;
                    cout << "Enter the message you want to decrypt: ";
                    cin.ignore();
                    getline(cin,sentence);
                    int times;
                    times =(Key.length()+1);
                    for(int i=0 ; i<Key.length() ; i++)
                        encrypt = encrypt + Key[i];
                    for(int y=0 ; y<Key.length() ; y++){
                        for(int z=0 ; z<26 ; z++){
                            if(Key[y] == Alpha[z])
                                Alpha[z]='*';
                        }
                    }
                    for(int x=0 ; x<26 ; x++){
                        if(Alpha[x]=='*')
                            continue;
                        else{
                            encrypt = encrypt + Alpha[x];
                            }
                    }

                    for(int i=0 ; i<sentence.length() ; i++){
                        for(int x=0 ; x<26 ; x++){
                            if(sentence[i] == encrypt[x])
                                result = result + Alpha1[x];
                        }
                    }
                    cout << result << endl << endl;
                    result.clear();
                }
            }

            else if (cipher == 7){
                string key_word , decrypted, encrypted;
                int x=0;
                char arr[6][6]={{},{'-','a','b','c','d','e'},{'-','f','g','h','i','j'},{'-','k','l','m','n','o'},{'-','p','q','r','s','t'},{'-','u','v','w','x','y'}};
                if(choice2 == 1){
                    cout << "\nEnter a 5 number Encryption key : ";
                    cin >> key_word;
                    cout << "Enter a sentence to encrypt : ";
                    cin.ignore();
                    getline(cin,decrypted);
                    for(int i=0 ; i<1 ; i++){
                        for(int j=1 ; j<6 ; j++){
                            arr[i][j]=key_word[x];
                            x++;
                        }
                    }
                    x=0;
                    for(int i=1; i<6; i++){
                        for(int j=0 ; j<1 ; j++){
                            arr[i][j]=key_word[x];
                            x++;
                        }
                    }
                    for(int l=0 ; l<decrypted.length() ; l++){
                        if(decrypted[l]==' '){
                            cout<<" ";
                        }
                        else{
                            for(int i=0 ; i<6 ; i++){
                                for(int j=0 ; j<6 ; j++){
                                    if(decrypted[l]==arr[i][j]){
                                        cout<<arr[0][i]<<arr[0][j];
                                    }
                                }
                            }
                        }
                    }
                    cout << endl << endl;
                }
                else if (choice2 == 2){
                    cout << "\nEnter a 5 number decryption key : ";
                    cin >> key_word;
                    for(int i=0; i<1; i++){
                        for(int j=1; j<6; j++){
                            arr[i][j]=key_word[x];
                            x++;
                        }
                    }
                    x=0;
                    for(int i=1; i<6; i++){
                        for(int j=0; j<1; j++){
                            arr[i][j]=key_word[x];
                            x++;
                        }
                    }
                    cout<<"Enter numbers to decrypt: ";
                    cin.ignore();
                    getline(cin,encrypted);
                    for(int i = 0; i < encrypted.size(); i += 2){
                        if(encrypted[i] == ' '){
                            cout << ' ';
                            i--;
                        }
                        else{
                            int row, col, realR, realC;
                            row = (int) encrypted[i];
                            col = (int) encrypted[i+1];
                            for(int r = 1; r < 6; r++){
                                if (((int) arr[r][0]) == row){
                                    realR = r;
                                }
                            }
                            for(int c = 1; c < 6; c++){
                                if (((int) arr[0][c]) == col){
                                    realC = c;
                                }
                            }
                            cout << arr[realR][realC];
                        }

                    }
                    cout << endl << endl;
                }
            }

            else if (cipher == 8){
                int Counter=0;
                string Space=" ";
                string Sentence;
                string Code;
                string English;
                if (choice2 == 1){
                    cout << "\nEnter the message you want to encrypt: ";
                    cin.ignore();
                    getline(cin,Sentence);
                    for(int x=0 ; x<Sentence.length() ; x++){
                        for(int y=0 ; y<27 ; y++){
                            if(Sentence[x] == alpha[y])
                                cout << morse[y] << " ";
                            else{
                                for (int i=0 ; i<27 ; i++){
                                    if (Sentence[x] == alpha[i])
                                    Counter++;}
                                if (Counter == 0){
                                    cout << "invalid input the program will now terminate.";
                                    return 0; }
                                }
                        }
                    }
                    cout << endl << endl;

                }
                else if (choice2 == 2){
                    cout << "\nEnter the message you want to decrypt: ";
                    cin.ignore();
                    getline(cin,Code);
                    Code = Code + ' ';

                    for(int i=0 ; i<Code.length() ; i++){
                        int g,j;
                        g = i+1;
                        j = i+2;
                        if(Code[i] == ' '){
                            if(Code[g]==' ' && Code[j]==' ')
                                cout<<" ";
                            English = English + morse_english(LetterM);
                            LetterM.clear();
                                       }

                        else{
                            LetterM = LetterM + Code[i];
                        }

                    }
                    cout << English << endl << endl;
                    English.clear();
                }
            }

            else if(cipher == 9){
                int a,choice ;
                char b;
                string key,msg ;
                if (choice2 == 1){
                    cout << "Enter The Key:";
                    cin >> key;

                    while(key.length()!=1){
                        cout << "This key should be one character" << endl;
                        cout << "Enter The key:";
                        cin >> key;
                    }
                    cout << "Please enter the message to cipher:";
                    cin.ignore();
                    getline(cin,msg);
                    key[0]=(char)tolower(key[0]);
                    for(int i=0 ; i<msg.length() ; i++){
                        msg[i]=(char)toupper(msg[i]);
                    }
                    cout << "Cipher text:";
                    for(int i=0 ; i<msg.length() ; ++i){
                        b = msg[i]^key[0];
                        cout << char (b) ;
                    }
                    cout << endl;
                    cout << "Cipher Hexadecimal:";
                    for(int i=0 ; i<msg.length() ; ++i){
                        a = (msg[i]^key[0]);
                        cout << hex<<a;
                    }
                    cout << endl << endl;
                }
                else if (choice2 == 2){
                    cout << "Enter The Key:";
                    cin >> key;

                    while(key.length()!=1){
                        cout << "This key should be one character" << endl;
                        cout << "Enter The key:";
                        cin >> key;
                    }
                    cout << "Enter the Message to Decipher:";
                    cin.ignore();
                    getline(cin,msg);
                    key[0]=(char)tolower(key[0]);
                    for(int i=0 ; i<msg.length() ; i++){
                        msg[i]=(char)toupper(msg[i]);
                    }
                    cout << "Message:";
                    for(int i=0 ; i<msg.length() ; ++i){
                        b = msg[i]^key[0];
                        cout << char (b) ;
                    }
                    cout << endl << endl;
                }
            }

            else if (cipher == 10){
                string decrypted , encrypted;
                if (choice2 == 1){
                    cout<<"\nEnter message required to encrypt : ";
                    cin.ignore();
                    getline(cin,decrypted);
                    encrypt3(decrypted);
                    cout << endl << endl;
                }
                else if (choice2 == 2){
                    cout<<"\nEnter message required to decrypt : ";
                    cin.ignore();
                    getline(cin,encrypted);
                    decrypt3(encrypted);
                    cout << endl << endl;
                }
            }
        }

        else if (choice1 == 2)
            return 0;
    }

    return 0;
}
