//
// Created by Samyok Nepal on 3/25/23.
//


int findFirstBigger(const vector<int>& vec, int x) {
    int left = 0, right = vec.size() - 1, ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (vec[mid] > x) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}

int findLastSmaller(const vector<int>& vec, int x) {
    int left = 0, right = vec.size() - 1, ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (vec[mid] < x) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}


int main(){
  vector<int> nums;
  vector<int> queries;

  vector<int> res;

  sort(nums.begin(), nums.end());

  vector<int> pfx;
  pfx.push_back(nums[0]);
  for(int i = 1; i < nums.size(); i++) pfx.push_back(pfx.back() + nums[i]);

  for(int q: queries){
    solve(nums, q);
  }
}