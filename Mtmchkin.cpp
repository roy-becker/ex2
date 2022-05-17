#include "Mtmchkin.h"
#include "Player.h"
#include "Card.h"


const int WIN_LEVEL = 10;


Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
{
    m_player = new Player(playerName);

    m_cards = new Card[numOfCards];
    for (int i = 0; i < numOfCards)
    {
        m_cards[i] = cardsArray[i];
    }

    m_numOfCards = numOfCards;

    m_currentCard = 0;

    m_status = GameStatus::MidGame;
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cards;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}

void Mtmchkin::playNextCard()
{
    const Card& card = m_cards[m_currentCard];

    card.printInfo();

    card.applyEncounter(m_player);

    if (m_player.isKnockedOut())
    {
        m_status = GameStatus::Loss;
    }
    else if (m_player.getLevel == WIN_LEVEL)
    {
        m_status = GameStatus::Win;
    }

    m_player.printInfo();

    m_currentCard++;
    if (m_currentCard == m_numOfCards)
    {
        m_currentCard = 0;
    }
}

bool Mtmchkin::isOver() const
{
    return (m_status != GameStatus::MidGame);
}