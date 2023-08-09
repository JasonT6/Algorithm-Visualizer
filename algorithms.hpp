#pragma once
#include <iostream>
#include <vector>
#include "node.hpp"
#include "board.hpp"
#include <list>
#include <queue>
#include "UIclass.hpp"

using namespace std;

class UIelements;

bool bfs(UIelements *curUI, node *start, node *end);

void Traceback(node *start, node *end);

bool dfs_recursive(UIelements *curUI, node *start, node *end);

bool dfs_with_stack(UIelements *curUI, node *start, node *end);

bool dijkstra(UIelements *curUI, node *start, node *end);

bool a_star(UIelements *curUI, node *start, node *end);
