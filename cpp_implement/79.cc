#include <iostream>
#include <string>
#include <vector>

/**
 * 这个解题思路还可以,但是实现起来的复杂度有点高,最终没有实现
 * */
using namespace std;
class SolutionWrong {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    CreateNeighboursForBoard(board);
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (board[i][j] == word[0]) {
          if (Search(board, board_neighbours_[i][j], word, 1)) {
            return true;
          }
        }
      }
    }
    return false;
  }

 private:
  struct neighbour {
    int m;
    int n;
    bool hit;
  };
  using neighbours = std::vector<neighbour>;
  std::vector<std::vector<neighbours>> board_neighbours_;
  int M;
  int N;

  bool Search(std::vector<std::vector<char>>& board, neighbours item_neighbours, string word, int pos) {
    if (pos == word.size()) {
      return true;
    }
    if (item_neighbours.size() == 0) {
      return false;
    }
    for (neighbour& iter : item_neighbours) {
      if (board[iter.m][iter.n] == word[pos] && iter.hit == false) {
        iter.hit = true;
        if (Search(board, board_neighbours_[iter.m][iter.n], word, pos + 1)) {
          return true;
        }
        iter.hit = false;
      }
    }
    return false;
  }
  void CreateNeighboursForBoard(std::vector<std::vector<char>>& board) {
    M = board.size();
    N = board[0].size();
    for (int i = 0; i < M; ++i) {
      std::vector<neighbours> item;
      for (int j = 0; j < N; ++j) {
        item.push_back(GetNeighbours(M, N, i, j));
      }
      board_neighbours_.push_back(item);
    }
  }
  neighbours GetNeighbours(const int M, const int N, int i, int j) {
    neighbours res;
    if (i - 1 >= 0) {
      res.push_back({i - 1, j, false});
    }
    if (i + 1 < M) {
      res.push_back({i + 1, j, false});
    }
    if (j - 1 >= 0) {
      res.push_back({i, j - 1, false});
    }
    if (j + 1 < N) {
      res.push_back({i, j + 1, false});
    }
    return res;
  }
};

/**
 * 这个方案超时了
 *
 * 这个方案能够学到的是如何使用特定的值初始化二维的 vector 数组
 * 还有一个点就是利用了参数传递时,传递对象,而不是传递引用和指针的特性
 *
 * 超时的原因: 每次调用时,都要拷贝构造 visited 二维数组,这就造成了很大的性能浪费
 * */
class SolutionSlow {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    board_ = board;
    word_  = word;
    M      = board.size();
    N      = board[0].size();
    std::vector<std::vector<bool>> visited(M, std::vector<bool>(N, false));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (check(visited, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  bool check(std::vector<std::vector<bool>> visited, int i, int j, int k) {
    if (board_[i][j] != word_[k] || visited[i][j] == true) {
      return false;
    }
    visited[i][j] = true;
    // board[i][j] = word[k]
    if (k + 1 == word_.size()) {
      return true;
    }
    // up
    if (i - 1 >= 0) {
      if (check(visited, i - 1, j, k + 1)) {
        return true;
      }
    }
    // down
    if (i + 1 < M) {
      if (check(visited, i + 1, j, k + 1)) {
        return true;
      }
    }
    // left
    if (j - 1 >= 0) {
      if (check(visited, i, j - 1, k + 1)) {
        return true;
      }
    }
    // right
    if (j + 1 < N) {
      if (check(visited, i, j + 1, k + 1)) {
        return true;
      }
    }
    return false;
  }
  std::vector<std::vector<char>> board_;
  string word_;
  int M;
  int N;
  /**
   * visited 不能是全局变量,如果是全局变量的话,维护 visited 的状态太复杂了
   * */
  bool* visited;
};

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    board_   = board;
    word_    = word;
    M        = board.size();
    N        = board[0].size();
    visited_ = std::vector<std::vector<bool>>(M, std::vector<bool>(N, false));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (check(i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  bool check(int i, int j, int k) {
    if (board_[i][j] != word_[k] || visited_[i][j] == true) {
      return false;
    }
    visited_[i][j] = true;
    if (k + 1 == word_.size()) {
      return true;
    }
    // up
    if (i - 1 >= 0) {
      if (check(i - 1, j, k + 1)) {
        return true;
      }
    }
    // down
    if (i + 1 < M) {
      if (check(i + 1, j, k + 1)) {
        return true;
      }
    }
    // left
    if (j - 1 >= 0) {
      if (check(i, j - 1, k + 1)) {
        return true;
      }
    }
    // right
    if (j + 1 < N) {
      if (check(i, j + 1, k + 1)) {
        return true;
      }
    }
    visited_[i][j] = false;
    return false;
  }
  std::vector<std::vector<char>> board_;
  std::vector<std::vector<bool>> visited_;
  string word_;
  int M;
  int N;
};

int main(int argc, char* argv[]) {
  std::vector<std::vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "ABCCED";
  Solution solution;
  //  std::cout << "Solution: " << solution.exist(board, word) << std::endl;
  //  std::cout << "Solution: " << solution.exist(board, "ABCB") << std::endl;
  std::cout << "Solution: " << solution.exist(board, "ABCESEEEFS") << std::endl;
}