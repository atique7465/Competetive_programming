class Food{
    public: 
        int rating;
        string name;

        Food(int rating, string name){
            this->rating = rating;
            this->name = name;
        }

        bool operator<(const Food& other) const{
            if(rating == other.rating) return name > other.name;
            return rating < other.rating;
        }
};

class FoodRatings {
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, priority_queue<Food>> highCousineFood; 
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            highCousineFood[cuisines[i]].push(Food(ratings[i], foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        foodRating[food] = newRating;
        highCousineFood[foodCuisine[food]].push(Food(newRating, food));
    }
    
    string highestRated(string cuisine) {
        Food high = highCousineFood[cuisine].top();
        while(foodRating[high.name] != high.rating){
            highCousineFood[cuisine].pop();
            high = highCousineFood[cuisine].top();
        }
        return high.name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
 
class FoodRatings_solution_02 {
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, set<pair<int, string>>> highCousineFood; 
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            highCousineFood[cuisines[i]].insert({-1 * ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto old = highCousineFood[foodCuisine[food]].find({-1 * foodRating[food], food});
        highCousineFood[foodCuisine[food]].erase(old);
        foodRating[food] = newRating;
        highCousineFood[foodCuisine[food]].insert({-1 * newRating, food});
    }
    
    string highestRated(string cuisine) {
        pair<int, string> p = *highCousineFood[cuisine].begin();
        return p.second;
    }
};