#include<iostream>
using namespace std;
#include <fstream>
#include <string>

enum Face { Zero=0, Two = 2, Three , Four , Five , Six , Seven , Eight , Nine, Ten , Jack , Queen , King , Ace};
enum Suit { Diamonds , Hearts , Clubs , Spades };

class Card
{
public:
    Card() {};
    Card( Face face, Suit suit )
    {
        myFace = face;
        mySuit = suit;
    }
    void get_cardvalues( Face &face, Suit &suit )
    {
        face = myFace;
        suit = mySuit;
    }
    Face myFace;
    Suit mySuit;
};

class Player
{
private:
    Card *hand;
    Face fullhouse_value[2];
    Face pair_value[2];
    Face triplet_value;
    Face quartet_value;
    Face highCard;
    int rank;
    bool royalFlush;
    bool straightFlush;
    bool quartet;
    bool fullHouse;
    bool sameSuit;
    bool straight;
    bool triplet;
    bool double_pair;
    bool single_pair;

    void sort();
    void isSameSuit();
    void isStraight();
    void isRoyalFlush();
    void check_pairs();
public:
    friend void winner(Player p,Player q,int& count);
    Player(char s[][5])
    {
        hand=new Card[5];
        highCard=Zero;
        sameSuit=false;
        straight=false;
        royalFlush=false;
        straightFlush=false;
        for(int i=0; i<5; i++)
        {
            switch (s[0][i])
            {
            case '2':
                hand[i].myFace=Two;
                break;
            case '3':
                hand[i].myFace=Three;
                break;
            case '4':
                hand[i].myFace=Four;
                break;
            case '5':
                hand[i].myFace=Five;
                break;
            case '6':
                hand[i].myFace=Six;
                break;
            case '7':
                hand[i].myFace=Seven;
                break;
            case '8':
                hand[i].myFace=Eight;
                break;
            case '9':
                hand[i].myFace=Nine;
                break;
            case 'T':
                hand[i].myFace=Ten;
                break;
            case 'J':
                hand[i].myFace=Jack;
                break;
            case 'Q':
                hand[i].myFace=Queen;
                break;
            case 'K':
                hand[i].myFace=King;
                break;
            case 'A':
                hand[i].myFace=Ace;
                break;
            default:
                cout<<"*** Invalid Entry ***:"<<s[0][i]<<endl;;
            }
            switch(s[1][i])
            {
            case 'D':
                hand[i].mySuit=Diamonds;
                break;
            case 'H':
                hand[i].mySuit=Hearts;
                break;
            case 'C':
                hand[i].mySuit=Clubs;
                break;
            case 'S':
                hand[i].mySuit=Spades;
                break;
            default:
                cout<<"***Invalid Entry***"<<endl;
            }
        }
        sort();
        isSameSuit();
        isStraight();
        if((sameSuit)&&(straight))
        {
            straightFlush=true;
            highCard=hand[4].myFace;
            sameSuit=false;
            straight=false;
            rank=2;
        }
        if(straightFlush)
        {
            isRoyalFlush();
        }
        if((!sameSuit)&&(!straight)&&(!straightFlush)&&(!royalFlush))
            check_pairs();
    }
    void display();
};

void Player::sort()
{
    Face temp;
    int exchanges;
    for(int pass=1; pass<5; pass++)
    {
        exchanges=0;
        for(int i=0; i<5-pass; i++)
        {
            if(hand[i].myFace>hand[i+1].myFace)
            {
                temp=hand[i].myFace;
                hand[i].myFace=hand[i+1].myFace;
                hand[i+1].myFace=temp;
                exchanges++;
            }
        }
        if(!exchanges)
            break;
    }
}

void Player::isSameSuit()
{
    sameSuit=true;
    for(int i=1; i<5; i++)
    {
        if(hand[0].mySuit!=hand[i].mySuit)
        {
            sameSuit=false;
            break;
        }
    }
    if(sameSuit)
    {
        rank=5;
        highCard=hand[4].myFace;
    }
}

void Player::isStraight()
{
    straight=true;
    for(int i=1; i<5; i++)
    {
        if((((int)hand[0].myFace)+i)!=hand[i].myFace)
        {
            straight=false;
            break;
        }
    }
    if(straight)
    {
        highCard=hand[4].myFace;
        rank=6;
    }
}

void Player::isRoyalFlush()
{
    if(hand[0].myFace==Ten)
    {
        royalFlush=true;
        straightFlush=false;
        rank=1;
    }
    else
        royalFlush=false;
}

void Player::check_pairs()
{
    int count=0;
    Face temp=Zero;
    int k=0;
    single_pair=false;
    triplet=false;
    quartet=false;
    fullHouse=false;
    for(int i=0; i<5; i++)
    {
        if(temp==hand[i].myFace)
            count++;
        else
        {
            if(count==1)
            {
                if(highCard<temp)
                    highCard=temp;
            }
            if(count==2)
            {
                pair_value[k++]=temp;
                single_pair=true;
            }
            if(count==3)
            {
                triplet_value=temp;
                triplet=true;
            }
            if((count==4)||(count==5))
            {
                quartet_value=temp;
                quartet=true;
            }
            count=1;
            temp=hand[i].myFace;
        }
        if(i==4)
        {
            if(count==1)
            {
                if(highCard<temp)
                    highCard=temp;
            }
            if(count==2)
            {
                pair_value[k++]=temp;
                single_pair=true;
            }
            if(count==3)
            {
                triplet_value=temp;
                triplet=true;
            }
            if((count==4)||(count==5))
            {
                quartet_value=temp;
                quartet=true;
            }
        }
    }
    if((single_pair)&&(k==2))
    {
        double_pair=true;
        single_pair=false;
        rank=8;
    }
    else if((single_pair)&&(triplet))
    {
        fullHouse=true;
        single_pair=false;
        triplet=false;
        rank=4;
    }
    else if(single_pair)
    {
        rank=9;
    }
    else if(triplet)
    {
        rank=7;
    }
    else if(quartet)
    {
        rank=3;
    }
    else
    {
        highCard=hand[4].myFace;
        rank=10;
    }
}
void Player::display()
{
    cout<<"rank="<<rank<<":";
    switch(rank)
    {
    case 1:
        cout<<"royal flush"<<", high card is:"<<highCard<<endl;
        break;
    case 2:
        cout<<"straight flush"<<", high card is:"<<highCard<<endl;
        break;
    case 3:
        cout<<"four of a kind"<<", high card is:"<<highCard<<endl;
        break;
    case 4:
        cout<<"full house"<<", high card is:"<<highCard<<endl;
        break;
    case 5:
        cout<<"flush"<<", high card is:"<<highCard<<endl;
        break;
    case 6:
        cout<<"straight"<<", high card is:"<<highCard<<endl;
        break;
    case 7:
        cout<<"three of a kind"<<", high card is:"<<highCard<<endl;
        break;
    case 8:
        cout<<"two pairs"<<", high card is:"<<highCard<<endl;
        break;
    case 9:
        cout<<"single pair"<<", high card is:"<<highCard<<endl;
        break;
    case 10:
        cout<<"high card:"<<", high card is:"<<highCard<<endl;
        break;
    }
}
void winner(Player p,Player q,int& count)
{
    if(p.rank<q.rank)
    {
        cout<<"Player 1 is the winner..."<<endl;
        count++;
    }
    else if(p.rank>q.rank)
        cout<<"Player 2 is the winner..."<<endl;
    else
    {
        switch(p.rank)
        {
        case 2:
            if(p.triplet_value>q.triplet_value)
            {
                cout<<"Player 1 is the winner..."<<endl;
                count++;
            }
            else if(p.triplet_value<q.triplet_value)
                cout<<"Player 2 is the winner..."<<endl;
            else
            {
                if(p.pair_value[0]>q.pair_value[0])
                {
                    cout<<"Player 1 is the winner..."<<endl;
                    count++;
                }
                else if(p.pair_value[0]<q.pair_value[0])
                    cout<<"Player 2 is the winner..."<<endl;
                else
                {
                    if(p.highCard>q.highCard)
                    {
                        cout<<"Player 1 is the winner..."<<endl;
                        count++;
                    }
                    else
                        cout<<"Player 2 is the winner..."<<endl;
                }
            }
            break;
        case 3:
            if(p.quartet_value>q.quartet_value)
            {
                cout<<"Player 1 is the winner..."<<endl;
                count++;
            }
            else if(p.quartet_value<q.quartet_value)
                cout<<"Player 2 is the winner..."<<endl;
            else
            {
                if(p.highCard>q.highCard)
                {
                    cout<<"Player 1 is the winner..."<<endl;
                    count++;
                }
                else
                    cout<<"Player 2 is the winner..."<<endl;
            }
            break;
        case 4:
            if(p.triplet_value>q.triplet_value)
            {
                cout<<"Player 1 is the winner..."<<endl;
                count++;
            }
            else if(p.triplet_value<q.triplet_value)
                cout<<"Player 2 is the winner..."<<endl;
            else
            {
                if(p.pair_value[0]>q.pair_value[0])
                {
                    cout<<"Player 1 is the winner..."<<endl;
                    count++;
                }
                else if(p.pair_value[0]<q.pair_value[0])
                    cout<<"Player 2 is the winner..."<<endl;
            }
            break;
        case 5:
        case 6:
            if(p.highCard>q.highCard)
            {
                cout<<"Player 1 is the winner..."<<endl;
                count++;
            }
            else
                cout<<"Player 2 is the winner..."<<endl;
            break;
        case 7:
            if(p.triplet_value>q.triplet_value)
            {
                cout<<"Player 1 is the winner..."<<endl;
                count++;
            }
            else if(p.triplet_value<q.triplet_value)
                cout<<"Player 2 is the winner..."<<endl;
            else
            {
                if(p.highCard>q.highCard)
                {
                    cout<<"Player 1 is the winner..."<<endl;
                    count++;
                }
                else
                    cout<<"Player 2 is the winner..."<<endl;
            }
            break;
        case 8:
            if(p.pair_value[0]>q.pair_value[0])
            {
                cout<<"Player 1 is the winner..."<<endl;
                count++;
            }
            else if(p.pair_value[0]<q.pair_value[0])
                cout<<"Player 2 is the winner..."<<endl;
            else
            {
                if(p.pair_value[1]>q.pair_value[1])
                {
                    cout<<"Player 1 is the winner..."<<endl;
                    count++;
                }
                else if(p.pair_value[1]<q.pair_value[1])
                    cout<<"Player 2 is the winner..."<<endl;
                else
                {
                    if(p.highCard>q.highCard)
                    {
                        cout<<"Player 1 is the winner..."<<endl;
                        count++;
                    }
                    else
                        cout<<"Player 2 is the winner..."<<endl;
                }
            }
            break;
        case 9:
            if(p.pair_value[0]>q.pair_value[0])
            {
                cout<<"Player 1 is the winner..."<<endl;
                count++;
            }
            else if(p.pair_value[0]<q.pair_value[0])
                cout<<"Player 2 is the winner..."<<endl;
            else
            {
                if(p.highCard>q.highCard)
                {
                    cout<<"Player 1 is the winner..."<<endl;
                    count++;
                }
                else
                    cout<<"Player 2 is the winner..."<<endl;
            }
            break;
        case 10:
            if(p.highCard>q.highCard)
            {
                cout<<"Player 1 is the winner..."<<endl;
                count++;
            }
            else
                cout<<"Player 2 is the winner..."<<endl;
        }
    }
}
int main()
{
    int count=0;
    char str[2][5];
    char str1[2][5];
    string line;
    ifstream myfile ("poker.txt");
    if (myfile.is_open())
    {
        for(int n=0;n<1000;n++)
        {
            int k=0;
            getline (myfile,line);
            for(int i=0;i<5;i++)
            {
                str[0][i]=line[k++];
                str[1][i]=line[k++];
                k++;
            }
            for(int i=0;i<5;i++)
            {
                str1[0][i]=line[k++];
                str1[1][i]=line[k++];
                k++;
            }
            cout<<n+1<<" ,";
            Player p(str);
            p.display();
            Player p1(str1);
            p1.display();
            winner(p,p1,count);
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    cout<<endl<<"count="<<count;
    return(0);
}
