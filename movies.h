#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


class Movies{
    public:
       
    Movies(string mov = "NULLMOVIE", double rat = 0) {
        movie = mov;
        rating = rat;
    }

    void setMovie(string mov) {
        movie = mov;
    }
    void setRating(double rat) {
        rating = rat;
    }

    //void printMovie() {
    //    cout << movie << endl;
    //}

    void printMovie() const{
        cout << movie << endl;
    }

    void printRating() {
        cout << rating << endl;
    }

    double getRating() const{
        return rating;
    }

    string getMovie() const{
        return movie;
    }

    void print() const{
        cout << movie << ", ";
        cout << fixed << setprecision(1) << rating << endl;
    }

    private:
        string movie;
        double rating;
};

ostream& operator<<(ostream& out, const Movies& mov) {
	mov.print();
	return out;
}

class alphaOrder {
public:
    bool operator() (Movies& a, Movies& b) const {
            return (a.getMovie() > b.getMovie());
    }
};
class numOrder { //has to be in decreaisng order
    public:
        bool operator() (Movies& a, Movies& b) const {
                if (a.getRating() == b.getRating()) {
            		return (a.getMovie() > b.getMovie());
		}
		else {
			return (a.getRating() < b.getRating());
		}
        }
};