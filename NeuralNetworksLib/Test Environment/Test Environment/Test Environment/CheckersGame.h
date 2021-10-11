#pragma once
#include "Game.h"
#include <vector>

enum class CheckerType
{
	Checker, King
};

enum class Team
{
	Black, White
};

struct Coord
{
	Coord(int x, int y) : x(x), y(y) {}
	int x, y;
};

struct Checker
{
	Checker(const Coord& coord, CheckerType type, Team team) : coord(coord), type(type), team(team) {}
	Coord coord;
	CheckerType type;
	Team team;
};

struct GameInfo
{
	GameInfo() : isEnd(false), winner(Team::Black), allCheckers(0), blackCheckers(0), whiteCheckers(0), countMoves(0) {}
	bool isEnd;
	Team winner;
	int allCheckers, blackCheckers, whiteCheckers;
	int countMoves;
};

class CheckersGame :
	public Game
{
public:
	CheckersGame();

	void NewGame();

	GameInfo GetInfo() const; //�������� ������� ���������� �� ����

	const Checker* GetChosenChecker(int x, int y) const; //�������� ��������� �����

	std::vector<const Checker*> GetCheckers() const; //��� ����� �� ����

	std::vector<Coord> GetPossibleMoves(const Checker* checker) const; //��������� ������ ��� ���� �����

	void Action(const Coord& coord); //������� �� ������

	virtual void Init(); //�������������

protected:

	Checker* chosenChecker;

	std::vector<Checker> checkers;

	GameInfo info;

private:
	void InitializeGame(CheckersGame*);
};

