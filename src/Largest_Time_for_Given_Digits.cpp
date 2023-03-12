class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int hours = 10*arr[0] + arr[1];
        int mins = 10*arr[2] + arr[3];
        int maxTime = -1;

        if(hours < 24 && mins < 60){
            int curTime = hours*60 + mins;
            maxTime = max(curTime, maxTime);
        }
        while(next_permutation(arr.begin(), arr.end())){
            hours = 10*arr[0] + arr[1];
            mins = 10*arr[2] + arr[3];

            if(hours < 24 && mins < 60){
                int curTime = hours*60 + mins;
                maxTime = max(curTime, maxTime);
            }
        }
        if(maxTime == -1) return "";

        //Coverting maxTime to a properly formatted string
        string result = "";
        string tmp = "";
        stringstream stream;

        stream << maxTime/60;
        stream >> result;

        if(maxTime/60 < 10) result = "0" + result;

        stream.clear();
        stream.str("");

        stream << maxTime%60;
        stream >> tmp;

        if(maxTime%60 < 10) result += ":0" + tmp;
        else result += ":" + tmp;

        return result;
    }
};