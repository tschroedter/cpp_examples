#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <ctime>
#include <cassert>

class Card
{
public:
    enum CardSuit
    {
        SUIT_CLUB,
        SUIT_DIAMOND,
        SUIT_HEART,
        SUIT_SPADE,
        MAX_SUITS
    };

    enum CardRank
    {
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_10,
        RANK_JACK,
        RANK_QUEEN,
        RANK_KING,
        RANK_ACE,
        MAX_RANKS
    };

    Card(
        CardRank rank = CardRank::RANK_2,
        CardSuit suit = CardSuit::SUIT_CLUB)
        : m_Rank(rank),
          m_Suit(suit)
    {
    }

    void print() const
    {
        switch (m_Rank)
        {
        case RANK_2: std::cout << '2';
            break;
        case RANK_3: std::cout << '3';
            break;
        case RANK_4: std::cout << '4';
            break;
        case RANK_5: std::cout << '5';
            break;
        case RANK_6: std::cout << '6';
            break;
        case RANK_7: std::cout << '7';
            break;
        case RANK_8: std::cout << '8';
            break;
        case RANK_9: std::cout << '9';
            break;
        case RANK_10: std::cout << 'T';
            break;
        case RANK_JACK: std::cout << 'J';
            break;
        case RANK_QUEEN: std::cout << 'Q';
            break;
        case RANK_KING: std::cout << 'K';
            break;
        case RANK_ACE: std::cout << 'A';
            break;
        default: std::cout << '?';
            break;
        }

        switch (m_Suit)
        {
        case SUIT_CLUB: std::cout << 'C';
            break;
        case SUIT_DIAMOND: std::cout << 'D';
            break;
        case SUIT_HEART: std::cout << 'H';
            break;
        case SUIT_SPADE: std::cout << 'S';
            break;
        default: std::cout << '?';
            break;
        }
    }

    int getCardValue() const
    {
        switch (m_Rank)
        {
        case RANK_2: return 2;
        case RANK_3: return 3;
        case RANK_4: return 4;
        case RANK_5: return 5;
        case RANK_6: return 6;
        case RANK_7: return 7;
        case RANK_8: return 8;
        case RANK_9: return 9;
        case RANK_10: return 10;
        case RANK_JACK: return 10;
        case RANK_QUEEN: return 10;
        case RANK_KING: return 10;
        case RANK_ACE: return 11;
        default: return 0;
        }
    }

private:
    CardSuit m_Suit;
    CardRank m_Rank;
};

class Deck
{
public:
    Deck()
    {
        int card = 0;
        for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
        {
            for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
            {
                m_Deck[card] = Card(
                    static_cast<Card::CardRank>(rank),
                    static_cast<Card::CardSuit>(suit));
                ++card;
            }
        }
    }
    void printDeck()
    {
        for (const auto &card : m_Deck)
        {
            card.print();
            std::cout << ' ';
        }

        std::cout << '\n';
    }

    void shuffleDeck()
    {
        // Step through each card in the deck
        for (int index = 0; index < 52; ++index)
        {
            // Pick a random card, any card
            int swapIndex = getRandomNumber(0, 51);
            // Swap it with the current card
            swapCard(m_Deck[index], m_Deck[swapIndex]);
        }

        m_CardIndex = 0;
    }

    const Card& dealCard()
    {
        assert(m_CardIndex < 52);

        return m_Deck[m_CardIndex++];
    }

private:
    std::array<Card, 52> m_Deck;
    int m_CardIndex;

    static void swapCard(Card &a, Card &b)
    {
        Card temp = a;
        a = b;
        b = temp;
    }

    // Generate a random number between min and max (inclusive)
    // Assumes srand() has already been called
    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
                                                                                     // evenly distribute the random number across our range
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }
};

char getPlayerChoice()
{
    std::cout << "(h) to hit, or (s) to stand: ";
    char choice;
    do
    {
        std::cin >> choice;
    } while (choice != 'h' && choice != 's');

    return choice;
}

bool playBlackjack(Deck &deck)
{
    // Set up the initial game state
    int playerTotal = 0;
    int dealerTotal = 0;

    // Deal the player one card
    dealerTotal += deck.dealCard().getCardValue();
    std::cout << "The dealer is showing: " << dealerTotal << '\n';

    // Deal the player two cards
    playerTotal += deck.dealCard().getCardValue();
    playerTotal += deck.dealCard().getCardValue();

    // Player goes first
    while (1)
    {
        std::cout << "You have: " << playerTotal << '\n';
        char choice = getPlayerChoice();
        if (choice == 's')
            break;

        playerTotal += deck.dealCard().getCardValue();

        // See if the player busted
        if (playerTotal > 21)
            return false;
    }

    // If player hasn't busted, dealer goes until he has at least 17 points
    while (dealerTotal < 17)
    {
        dealerTotal += deck.dealCard().getCardValue();
        std::cout << "The dealer now has: " << dealerTotal << '\n';
    }

    // If dealer busted, player wins
    if (dealerTotal > 21)
        return true;

    return (playerTotal > dealerTotal);
}

void quiz4()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
    rand(); // If using Visual Studio, discard first random value

    Deck deck;
    deck.shuffleDeck();

    if (playBlackjack(deck))
        std::cout << "You win!\n";
    else
        std::cout << "You lose!\n";
}

/*
 * Holy moly! Where do we even begin? Don’t worry, we can do this, but we’ll need a strategy here. This Blackjack program is 
 * really composed of four parts: the logic that deals with cards, the logic that deals with the deck of cards, the logic 
 * that deals with dealing cards from the deck, and the game logic. Our strategy will be to work on each of these pieces 
 * individually, testing each part with a small test program as we go. That way, instead of trying to convert the entire 
 * program in one go, we can do it in 4 testable parts.
 * 
 * Start by copying the original program into your IDE, and then commenting out everything except the #include lines.
 * 
 * 4a) Let’s start by making Card a class instead of a struct. The good news is that the Card class is pretty similar to the 
 * Monster class from the previous quiz question. First, move the enums for CardSuit, CardRank inside the card class as 
 * public definitions (they’re intrinsically related to Card, so it makes more sense for them to be inside the class, not 
 * outside). Second, create private members to hold the CardRank and CardSuit (name them m_rank and m_suit accordingly). 
 * Third, create a public constructor for the Card class so we can initialize Cards. Forth, make sure to assign default 
 * values to the parameters so this can be used as a default constructor (pick any values you like). Finally, move the 
 * printCard() and getCardValue() functions inside the class as public members (remember to make them const!).
 * 
 * 4b) Okay, now let’s work on a Deck class. The deck needs to hold 52 cards, so use a private std::array member to create 
 * a fixed array of 52 cards named m_deck. Second, create a constructor that takes no parameters and initializes m_deck with 
 * one of each card (modify the code from the original main() function). Inside the initialization loop, create an anonymous 
 * Card object and assign it to your deck element. Third, move printDeck into the Deck class as a public member. Fourth, move 
 * getRandomNumber() and swapCard() into the Deck class as a private static members (they’re just helper functions, so they 
 * don’t need access to *this). Fifth, move shuffleDeck into the class as a public member.
 * 
 * Hint: The trickiest part of this step is initializing the deck using the modified code from the original main() function. 
 * The following line shows how to do that.
 * _deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
 * 
 * 4c) Now we need a way to keep track of which card is next to be dealt (in the original program, this is what cardptr was 
 * for). First, add a int member named m_cardIndex and initialize it to 0. Create a public member function named dealCard(), 
 * which should return a const reference to the current card and advance the index. shuffleDeck() should also be updated to 
 * reset m_cardIndex (since if you shuffle the deck, you’ll start dealing from the top of the deck again).
 * 
 * 4d) Almost there! Now, just fix up the remaining program to use the classes you wrote above. Since most of the 
 * initialization routines has been moved into the classes, you can jettison them.
 */
