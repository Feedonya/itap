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
  
  Song operator >(Song s1, Song s2) {
  if (s1.GetPerformer() < s2.GetPerformer()) {
    return true;
  }
  else {
    return false;
  }
}

  Song operator <(Song s1, Song s2) {
  if (s1.name > s2.name){
    return false;
  }
  else {
    return true;
  }
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
  
};


void GetSongInfo(Song s) {
  cout << "Song by " << s.GetPerformer() << ". Music author is " << s.GetSongAuthor() << ". Lyrics author is " << s.GetLyricsAuthor() << endl;
  cout << "Lyrics:" << endl << s.GetLyrics();
}


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
