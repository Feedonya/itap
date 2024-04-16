#include <iostream>
#include <string>

using namespace std;

class Person {
private:
  string name;
  string second_name;

public:
  Person() {
    name = "No";
    second_name = "Name";
  }

  Person(string n, string s) {
    name = n;
    second_name = s;
  }

  string GetName() {
    return name + " " + second_name;
  }
  
	bool operator > (Person s1) {
		return name > s1.name;
  	}
};

class Song {
private:
  Person performer;
  Person song_author;
  Person lyrics_author;
  string lyrics;
public:
  Song(Person p, Person s, Person l, string lyr) {
    performer = p;
    song_author = s;
    lyrics_author = l;
    lyrics = lyr;
  }
  void ChangeLyrics(string nLyrics) {
    lyrics = nLyrics;
  }

  string GetPerformer() {
    return performer.GetName();
  }

  string GetSongAuthor() {
    return song_author.GetName();
  }

  string GetLyricsAuthor() {
    return lyrics_author.GetName();
  }

  string GetLyrics() {
    return lyrics;
  }
  
  string GetSongInfo() {
    return << "Song by " << performer << ". Music author is " << song_author() << ". Lyrics author is " << lyrics_author() << "Lyrics:" << endl << lyrics;;
}
};




int main() {

  Person p1("Juju", "Baba");
  Person p2("Sergey", "Lazarev");

  Song s1(p1, p1, p1, "bbebebebebebebebebebeebebebeb");
  Song s2(p1, p1, p1, "aaaaaaaaa alalalalalal");
  Song s3(p2, p2, p2, "eifioqfoqhfjqbkjfbjkqbfjkqbfbqfkbj");

  cout << (s1 > s2).GetPerformer();
  cout << '\n';
  cout << (s1 > s3).GetPerformer();

  cout << endl << endl;

  GetSongInfo(s1);

  return 0;
}
