class FoodRatings {
public:
    map<string,set<pair<int,string>>>ms;
    map<string,int>foodR;
    map<string,string>cus;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            ms[cuisines[i]].insert({-ratings[i],foods[i]});
            foodR[foods[i]]=ratings[i];
            cus[foods[i]]=cuisines[i];
        }
    }
    void changeRating(string food, int newRating) {
        int prevR = foodR[food];
        foodR[food]=newRating;
        ms[cus[food]].erase({-prevR,food});
        ms[cus[food]].insert({-newRating,food});
    }
    string highestRated(string cuisine) {
        pair<int,string> p = *ms[cuisine].begin();
        return p.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */