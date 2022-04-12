#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <map>
#include <queue>
using namespace sol1086;
using namespace std;

/*takeaways
  - use a ordered map so we can sort it by student id in ascending
    order
  - for each map entry the value is a max heap which stores the
    student score in descending order
*/

vector<vector<int>> Solution::average(vector<vector<int>> &scores)
{
  auto m = map<int, priority_queue<int>>();

  for (auto s : scores)
    m[s[0]].push(s[1]);

  auto result = vector<vector<int>>();

  for (auto &[id, scores] : m)
  {
    auto sum = 0;
    /* each student has at least 5 scores */
    for (auto i = 0; i < 5; i++)
      sum += scores.top(), scores.pop();
    result.push_back({id, sum / 5});
  }

  return result;
}