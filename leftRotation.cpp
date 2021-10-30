/*
Left Rotation
A left rotation operation on an array of size shifts each of the array's elements unit to the left. For
example, if left rotations are performed on array , then the array would become
.
Given an array of integers and a number, , perform left rotations on the array. Then print the updated
array as a single line of space-separated integers.
Input Format
The first line contains two space-separated integers denoting the respective values of (the number of
integers) and (the number of left rotations you must perform).
The second line contains space-separated integers describing the respective elements of the array's initial
state.
Constraints
Output Format
Print a single line of space-separated integers denoting the final state of the array after performing left
rotations.
Sample Input
5 4
1 2 3 4 5
Sample Output
5 1 2 3 4
Explanation
When we perform left rotations, the array undergoes the following sequence of changes:
Thus, we print the array's final state as a single line of space-separated values, which is 5 1 2 3 4 .

solution:
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'rotateLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

vector<int> rotateLeft(int d, vector<int> arr) {
    vector<int>result;
    for(auto i=arr.begin()+d;i!=arr.end();i++)
    result.push_back(*i);
    for (auto i=arr.begin(); i!=arr.begin()+d; i++) {
    result.push_back(*i);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = rotateLeft(d, arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
