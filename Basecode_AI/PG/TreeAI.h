#pragma once

#include "../Utils/DList.h"
#include "../Utils/Tree/Tree.h"
#include "../Utils/Type/Bool.h"
#include "../Utils/Type/Float.h"
#include "Function.h"

// ------------------------------ Fonctions basiques ------------------------------

// Type de retour: TYPE_NULL

void* __progn(TreeNode* node);

// Type de retour: TYPE_REAL

void* __srt(TreeNode* node);
void* __add(TreeNode* node);
void* __sub(TreeNode* node);
void* __mul(TreeNode* node);
void* __div(TreeNode* node);

// Type de retour: TYPE_BOOL

void* __not(TreeNode* node);
void* __equal(TreeNode* node);
void* __sup(TreeNode* node);
void* __inf(TreeNode* node);
void* __and(TreeNode* node);
void* __or(TreeNode* node);

// Type de retour: *

void* __if(TreeNode* node);

// ------------------------------ TreeAI >> Programme ------------------------------

/// @brief Profondeur maximum dans un programme.
#define MAX_DEPTH 4

/// @brief Nombre maximum de noeuds dans un programme.
#define MAX_NODE 200

/// @brief Cr�e un programme al�atoire.
Tree* TreeAI_Create(DList*** F, TypeID res, int depth);

/// @brief Ex�cute un programme (sous-arbre).
void* TreeAI_ExecuteRec(TreeNode* node);

/// @brief Ex�cute un programme.
void* TreeAI_Execute(Tree* tree);

/// @brief Compare le score de 2 programmes.
int TreeAI_CompareScore(Tree* tree1, Tree* tree2);

/// @brief S�lectionne un sous-arbre al�atoire � chaque arbre et �changent les sous-arbres.
void TreeAI_Crossover(Tree* tree1, Tree* tree2);

/// @brief Modifie une fonction al�atoirement par une autre.
void TreeAI_Mutation(Tree* tree, DList*** F);
