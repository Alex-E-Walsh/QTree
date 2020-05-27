#include "qtree.h"
#include <exception>
#include <iostream>

const std::string QuestionTree::INTERNAL_HEADER("D:");
const std::string QuestionTree::LEAF_HEADER("FG:");

//Ask the user a yes/no question, and get a true/false answer, respectively
bool QuestionTree::getAnswer(const std::string& question) {
  std::cout << question << std::endl;
  std::string response("?");
  do {
    std::cout << "Enter (y)es or (n)o: ";
    std::getline(std::cin, response);
  } while (!std::cin.fail() && response[0] != 'y' && response[0] != 'n');
  if (response[0] == 'y') {
    return true;
  } else if (response[0] == 'n') {
    return false;
  } else {
    throw new std::exception();
  }
}

//Replace a current child of this node with a new one.
//If orig is a child of this node, then replace it with newChild
//Preconditions:
// * orig should be one of the children of this node
// * a pointer to orig should be held elsewhere so it is not leaked
//Postconditions:
// * if orig was replaced and newChild is not NULL,
//       newChild's parent will be set to this
//Error cases for which this method will throw an exception
// * orig is not one of this node's children
//Undefined behavior if orig is both the yes and no child of this
void QuestionTree::Distinguish::replaceChild(Node* orig, Node* newChild) {
  //Find which child needs to be replaced, and do the replacing
  Node* temp = orig; //create a placeholder for orig
  if(orig->parent == ){ //if its the node we're looking for

  }
  //FIXME: only throw an exception if we have a problem, like not finding orig
  throw new std::exception();
}

//Play a guessing game, beginning with the question described in this node.
void QuestionTree::Distinguish::play() {
  bool answer = QuestionTree::getAnswer(q);
  //Base case: when we get to a leaf, do a final guess
  if(yesSubtree == NULL && noSubtree == NULL){
    QuestionTree::FinalGuess::play(); //final guess that calls expand
  }
  if(answer == true){ //if answer y, move to the right subtree
    root = yesSubtree; //set the root equal to the right child

  } else { //else answer n, move to the left subtree
    root = noSubtree; //set the root equal to the left child
  }
  QuestionTree::Distinguish::play();
}

//Invoke the user interface to:
//   create another final guess
//   create a new question that will distinguish between the two final guesses
//   make this node a child of the new distinguish node, and in this node's former
//      parent, replace this node with the new distinguish node subtree.
void QuestionTree::FinalGuess::expand() {
  std::cin.clear();
  std::cout << "What were you thinking of?  "
    << "Include an article (a, an, the) if appropriate:" << std::endl;
  std::string response;
  //Need to use this to read a whole line/phrase instead of one word
  std::getline(std::cin, response);
  std::cout << "What is a yes/no question that would distinguish between "
    << guess << " and " << response << "?" << std::endl;
  std::string question;
  //Need to use this to read a whole line/phrase instead of one word
  std::getline(std::cin, question);
  bool answerForNew = QuestionTree::getAnswer(std::string("What is the correct answer for ") + response + '?');

  FinalGuess* newGuess = new FinalGuess(response, tree);
  Distinguish* newQuestion = new Distinguish(response, tree, this->getParent, )

  //FIXME: create new question node with appropriate yes/no children, and
  //put the new question node in the tree
}

//Play a guessing game, beginning with the question described in this node.
void QuestionTree::FinalGuess::play() {
  std::string question;
  question = std::string("Are you thinking of ") + guess + std::string("?");
  if (QuestionTree::getAnswer(question)) {
    std::cout << "Naturally." << std::endl;
  } else {
    std::cout << "Well, drat." << std::endl;
    if (tree.expand()) {
      expand();
    }
  }
}
