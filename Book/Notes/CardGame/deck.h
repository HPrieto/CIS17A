#ifndef DECK_H
#define DECK_H

template <class T>
class Deck{
    private:
        int *index;   //Index of the 52 cards
        T **card;  //Array of cards in the deck
        int delt;     //Count of how many cards have been delt
        int nCrds;    //Number of cards in the deck
        float pctShuf;//Percentage cards delt, when to Shuffle
        int nShufle;  //Number of shuffles to give random results
    public:
        Deck();                    //Construct the Deck
        ~Deck();                   //Destroy the Deck
        T **deal(int);          //Deal the cards
        void shuffle();            //Shuffle the index
        void cleanup(T **,int); //Clean up the cards delt
};

template <class T>
Deck<T>::Deck(){
    nCrds=52;
    pctShuf=0.8;
    nShufle=7;
    index=new int[nCrds];
    card=new T*[nCrds];
    for(int i=0;i<nCrds;i++){
        index[i]=i;
        card[i]=new T(i);
    }
    delt=0;
}

template <class T>
Deck<T>::~Deck(){
    delete []index;
    for(int i=0;i<nCrds;i++){
        delete card[i];
    }
    delete []card;
}

template <class T>
T **Deck<T>::deal(int toDeal){
    if(delt>pctShuf*nCrds)shuffle();
    T **hand=new T*[toDeal];
    for(int i=1;i<=toDeal;i++){
        hand[i-1]=new T(index[delt++]);
    }
    return hand;
}

template <class T>
void Deck<T>::shuffle(){
    //Shuffle
    for(int shuffle=1;shuffle<=nShufle;shuffle++){
        for(int eachCrd=0;eachCrd<nCrds;eachCrd++){
            int rnd=rand()%nCrds;
            int temp=index[eachCrd];
            index[eachCrd]=index[rnd];
            index[rnd]=temp;
        }
    }
}

template <class T>
void Deck<T>::cleanup(T **hand,int nCrds){
    for(int i=0;i<nCrds;i++){
        delete hand[i];
    }
    delete []hand;
}

#endif /* DECK_H */
