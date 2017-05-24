#include "stdafx.h"
#include <iostream>
#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <vector>

enum Ranks
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
    MaxRank
};

enum Suits
{
    Clubs,
    Diamonds,
    Hearts,
    Spades,
    MaxSuit
};

struct Card
{
    Ranks rank;
    Suits suit;
};

char convertRankToChar(const Ranks rank)
{
    switch (rank)
    {
    case Two: return '2';
    case Three: return '3';
    case Four: return '4';
    case Five: return '5';
    case Six: return '6';
    case Seven: return '7';
    case Eight: return '8';
    case Nine: return '9';
    case Ten: return 'T';
    case Jack: return 'J';
    case Queen: return 'Q';
    case King: return 'K';
    case Ace: return 'A';
    default: return '?';
    }
}

char convertSuitToChar(const Suits suit)
{
    switch (suit)
    {
    case Clubs: return 'C';
    case Diamonds: return 'D';
    case Hearts: return 'H';
    case Spades: return 'S';
    default: return '?';
    }
}

void printCard(const Card& card)
{
    char rank = convertRankToChar(card.rank);
    char suit = convertSuitToChar(card.suit);

    std::cout << suit << rank;
}

void swapCard(Card& one, Card& two)
{
    Card temp = one;

    one = two;
    two = temp;
}

void printCards(const std::vector<Card>& cards)
{
    for (const auto& card : cards)
    {
        printCard(card);

        std::cout << " ";
    }

    std::cout << std::endl;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::vector<Card>& cards)
{
    for (auto& card : cards)
    {
        int randomIndex = getRandomNumber(0, 51);

        swapCard(card, cards[randomIndex]);
    }
}

int getCardValue(const Card& card)
{
    switch (card.rank)
    {
    case Two: return 2;
    case Three: return 3;
    case Four: return 4;
    case Five: return 5;
    case Six: return 6;
    case Seven: return 7;
    case Eight: return 8;
    case Nine: return 9;
    case Ten: return 10;
    case Jack: return 10;
    case Queen: return 10;
    case King: return 10;
    case Ace: return 11;
    default: return 0;
    }
}

int getCardsValueForAceIsOnePoint(const std::vector<Card>& cards)
{
    int total = 0;

    for (const auto& card : cards)
    {
        if (card.rank == Ace)
        {
            total += 1;
        }
        else
        {
            total += getCardValue(card);
        }
    }

    return total;
}

int getCardsValue(const std::vector<Card>& cards)
{
    int total = 0;

    for (const auto& card : cards)
    {
        total += getCardValue(card);
    }

    if (total > 21)
    {
        total = getCardsValueForAceIsOnePoint(cards);
    }

    return total;
}

void createDeck(std::vector<Card>& deck)
{
    deck.resize(52);

    int index = 0;
    for (int suits = 0; suits < Suits::MaxSuit; suits++)
    {
        for (int ranks = 0; ranks < Ranks::MaxRank; ranks++)
        {
            deck[index].suit = static_cast<Suits>(suits);
            deck[index].rank = static_cast<Ranks>(ranks);

            index++;
        }
    }
}

void dealCard(std::vector<Card>& deck, int& nextCardIndexInDeck, std::vector<Card>& cards)
{
    int newsize = cards.size() + 1;

    cards.resize(newsize);
    cards[newsize - 1] = deck[nextCardIndexInDeck++];
}

char getPlayerHitsOrStands()
{
    char input;

    do
    {
        std::cout << "(H)it or (S)tand? ";
        std::cin >> input;

        // if the user entered something invalid
        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
        }
    }
    while (!(input == 'h' || input == 's'));

    return input;
}

void dealerGetsACard(std::vector<Card> deck, int& nextCardIndexInDeck, std::vector<Card>& dealer)
{
    dealCard(deck, nextCardIndexInDeck, dealer);
    std::cout << "Dealer received a card...\n";
}

void playerGetsACard(std::vector<Card> deck, int& nextCardIndexInDeck, std::vector<Card>& player)
{
    dealCard(deck, nextCardIndexInDeck, player);
    std::cout << "Player received a card...\n";
}

void initialize()
{
    srand(static_cast<int>(time(nullptr))); // using build in random number generator
    rand(); // Visual Studio bug
}

enum Winner
{
    Player,
    Dealer,
    None
};

Winner checkForWinner(const std::vector<Card>& dealer, const std::vector<Card>& player)
{
    int totalDealer = getCardsValue(dealer);
    int totalPlayer = getCardsValue(player);

    if (totalPlayer == 21)
    {
        std::cout << "Player wins! :-)\n";
        return Player;
    }

    if (totalPlayer > 21)
    {
        std::cout << "Dealer wins! :-)\n";
        return Dealer;
    }

    if (totalDealer == 21)
    {
        std::cout << "Dealer wins! :-)\n";
        return Dealer;
    }

    if (totalDealer > 21)
    {
        std::cout << "Player wins! :-)\n";
        return Player;
    }

    if (totalDealer > totalPlayer)
    {
        std::cout << "Dealer wins! :-)\n";
        return Dealer;
    }

    return None;
}

void printDealerCards(std::vector<Card>& dealer)
{
    int totalDealer = getCardsValue(dealer);
    std::cout << "\nDealer currently at " << totalDealer << " holding the following cards:\n";
    printCards(dealer);
}

void doPlayerStands(const std::vector<Card>& deck, int& nextCardIndexInDeck, std::vector<Card>& dealer, const std::vector<Card>& player)
{
    bool isFinished = false;

    do
    {
        printDealerCards(dealer);

        Winner winner = checkForWinner(dealer, player);

        switch (winner)
        {
        case Player:
        case Dealer:
            isFinished = true;
            break;
        default:
            dealerGetsACard(deck, nextCardIndexInDeck, dealer);
        }
    }
    while (!isFinished);
}

void printPlayerCards(std::vector<Card> player)
{
    int totalPlayer = getCardsValue(player);
    std::cout << "\nYou are currently at " << totalPlayer << " holding the following cards:\n";
    printCards(player);
}

void quiz6()
{
    initialize();

    std::vector<Card> deck{};
    createDeck(deck);
    shuffleDeck(deck);

    int nextCardInDeck = 0;
    std::vector<Card> dealer{0};
    std::vector<Card> player{0};

    dealerGetsACard(deck, nextCardInDeck, dealer);

    playerGetsACard(deck, nextCardInDeck, player);
    playerGetsACard(deck, nextCardInDeck, player);

    bool isFinished = false;

    do
    {
        printPlayerCards(player);

        Winner winner = checkForWinner(dealer, player);

        if (winner != None)
        {
            isFinished = true;
        }

        char hitOrStand = getPlayerHitsOrStands();
        bool isPlayerStands = hitOrStand == 's' || hitOrStand == 'S';

        if (isPlayerStands)
        {
            std::cout << "Player stands...\n";
            doPlayerStands(deck, nextCardInDeck, dealer, player);
            isFinished = true;
        }
        else
        {
            std::cout << "Player hits...\n";
            playerGetsACard(deck, nextCardInDeck, player);
        }
    }
    while (!isFinished);
}

/*
 * 6) Let’s pretend we’re writing a card game.
 * 
 * 6a) A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create enumerations for the card ranks 
 *     (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace) and suits (clubs, diamonds, hearts, spades).
 * 
 * 6b) Each card will be represented by a struct named Card that contains a rank and a suit. Create the struct.
 * 
 * 6c) Create a printCard() function that takes a const Card reference as a parameter and prints the card rank 
 *     and value as a 2-letter code (e.g. the jack of spades would print as JS).
 *     
 * 6d) A deck of cards has 52 cards. Create an array (using std::array) to represent the deck of cards, and 
 *     initialize it with one of each card.
 * 
 * Hint: Use static_cast if you need to convert an integer into an enumerated type.
 * 
 * 6f) Write a swapCard function that takes two Cards and swaps their values.
 * 
 * 6g) Write a function to shuffle the deck of cards called shuffleDeck(). To do this, use a for loop to step 
 *     through each element of your array. Pick a random number between 1 and 52, and call swapCard with the 
 *     current card and the card picked at random. Update your main function to shuffle the deck and print out 
 *     the shuffled deck.
 *
 * Hint: Review lesson 5.9 -- Random number generation for help with random numbers.
 * Hint: Don’t forget to call srand() at the top of your main function.
 * Hint: If you’re using Visual Studio, don’t forget to call rand() once before using rand.
 * 
 * 6h) Write a function named getCardValue() that returns the value of a Card (e.g. a 2 is worth 2, a ten, jack, 
 * queen, or king is worth 10. Assume an Ace is worth 11).
 * 
 * todo
 * 
 * 7) Alright, challenge time! Let’s write a simplified version of Blackjack. If you’re not already 
 *    familiar with Blackjack, the Wikipedia article for Blackjack has a summary.
 *    
 *    Here are the rules for our version of Blackjack:
 *      The dealer gets one card to start 
 *      (in real life, the dealer gets two, but one is face down so it doesn’t matter at this point).
 *      The player gets two cards to start.
 *      The player goes first.
 *      A player can repeatedly hit or stand.
 *      If the player stands, their turn is over.
 *      If the player hits, they get another card and the value of that card is added to their total score.
 *      An ace normally counts as a 1 or an 11 (whichever is better for the total score). For simplicity, 
 *      we’ll count it as an 11 here.
 *      If the player goes over a score of 21, they bust and lose immediately.
 *      The dealer goes after the player.
 *      The dealer repeatedly draws until they reach a score of 17 or more, at which point they stand. todo
 *      If the dealer goes over a score of 21, they bust and the player wins immediately.
 *      Otherwise, if the player has a higher score than the dealer, the player wins. Otherwise, the player loses.
 *      In our simplified version of Blackjack, we’re not going to keep track of which specific cards the player 
 *      and the dealer have been dealt. We’ll only track the sum of the values of the cards they have been dealt 
 *      for the player and dealer. This keeps things simpler.
 *      
 *   Start with the code you wrote in quiz #6. Create a function named playBlackjack() that returns true if the 
 *   player wins, and false if they lose. This function should:
 *      Accept a shuffled deck of cards as a parameter.
 *      Initialize a pointer to the first Card named cardPtr. This will be used to deal out cards from the deck 
 *      (see the hint below).
 *      Create two integers to hold the player’s and dealer’s total score so far.
 * 
 * Implement Blackjack as defined above.
 * 
 * Hint: The easiest way to deal cards from the deck is to keep a pointer to the next card in the deck that will be dealt out. Whenever we need to deal a card, we get the value of the current card, and then advance the pointer to point at the next card. This can be done in one operation:
 * 1 getCardValue(*cardPtr++);
 * This returns the current card’s value (which can then be added to the player or dealer’s total), and advances cardPtr to the next card.
 */
