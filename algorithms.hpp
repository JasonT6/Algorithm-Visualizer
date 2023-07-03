#pragma once
#include <iostream>
#include <vector>
#include "node.hpp"
#include "board.hpp"
#include <list>

using namespace std;

bool bfs(node *start, node *end);

void Traceback(node *start, node *end);

bool dfs_recursive(node *start, node *end);

bool dfs_with_stack(node *start, node *end);