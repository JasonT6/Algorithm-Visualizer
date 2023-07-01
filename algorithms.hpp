#pragma once
#include <iostream>
#include <vector>
#include "node.hpp"
#include "board.hpp"
#include <list>
using namespace std;

bool bfs(node *start, node *end);

void bfsTraceback(node *start, node *end);
