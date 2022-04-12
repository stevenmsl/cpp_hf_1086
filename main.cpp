#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1086;

/*
Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation:
The average of the student with id = 1 is 87.
The average of the student with id = 2 is 88.6.
But with integer division their average converts to 88.
*/

tuple<vector<vector<int>>, vector<vector<int>>> testFixture1()
{
  auto input = vector<vector<int>>{
      {1, 91}, {1, 92}, {2, 93}, {2, 97}, {1, 60}, {2, 77}, {1, 65}, {1, 87}, {1, 100}, {2, 100}, {2, 76}};

  auto output = vector<vector<int>>{
      {1, 87}, {2, 88}};
  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << "result: " << Util::toString(sol.average(get<0>(f))) << endl;
}

main()
{
  test1();
  return 0;
}