
#include <iostream>
#include <string>

using namespace std;

class Person{
private:
    string name;
    string second_name;

public:
    Person(){
		name = "No"; 
		second_name = "Name";
    }

    Person(string n, string s){
		name = n;
		second_name = s;
    }

    string GetName(){
		return name + " " + second_name;
	}

    bool operator > (Person s1){
		return name > s1.name;
	}
	bool operator < (Person s1){
		return name < s1.name;
	}
	bool operator == (Person s1){
		return name == s1.name;
	}
	
};

class Song{
    private:
		Person performer;
		Person song_author;
		Person lyrics_author;
		string lyrics;
		static int count;	
    public:
    Song(Person p, Person s, Person l, string lyr){
		performer = p;
		song_author = s;
		lyrics_author = l;
		lyrics = lyr;
		count++;
    }

    void ChangeLyrics(string nLyrics){
    	lyrics = nLyrics;
    }

    string GetPerformer(){
    	return performer.GetName();
    }

    string GetSongAuthor(){
    	return song_author.GetName();
    }

    string GetLyricsAuthor(){
    	return lyrics_author.GetName();
    }

    string GetLyrics(){
    	return lyrics;
    }

	static int GetCount(){
    	return count;
    }
    
    string GetSongInfo(){
		string temp;
		temp.append("Èñïîëíèòåëü: ").append(GetPerformer()).append(" Àâòîð ìóçûêè: ").append(GetSongAuthor()).append(" Àâòîð ñëîâ: ").append(GetLyricsAuthor()).append(" Òåêñò ïåñíè: ").append(GetLyrics()).append("\n");
		return temp;
  	}
  	
  	bool operator > (Song s1){
		return performer > s1.performer;
	}
	bool operator < (Song s1){
		return performer < s1.performer;
	}
	bool operator == (Song s1){
		return performer == s1.performer;
	}
};


int Song::count = 0;

int main(){
    setlocale(LC_ALL, "Russian");

	Person p1("Juju", "Baba");
	Person p2("Sergey", "Lazarev");

	Song s1(p1, p1, p1, "bbebebebebebebebebebeebebebeb");
	Song s2(p1, p1, p1, "aaaaaaaaa alalalalalal");
	Song s3(p2, p2, p2, "eifioqfoqhfjqbkjfbjkqbfjkqbfbqfkbj");

	cout << (s1 == s2);
	cout << '\n';

	cout << s3.GetCount() << '\n';
	
	cout << s1.GetSongInfo();
	
	s1.ChangeLyrics("hello");
	
	cout << s1.GetSongInfo();

	return 0;
}
