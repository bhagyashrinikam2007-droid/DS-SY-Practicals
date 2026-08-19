#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string title;
    Song* next;
    Song* prev;

    Song(string title) {
        this->title = title;
        next = NULL;
        prev = NULL;
    }
};

class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    
    void addSong(string title) {
        Song* newSong = new Song(title);

        if (head == NULL) {
            head = tail = current = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }

    
    void nextSong() {
        if (current == NULL) {
            cout << "Playlist is empty.\n";
        } else if (current->next == NULL) {
            cout << "Already at the last song.\n";
        } else {
            current = current->next;
            cout << "Now playing: " << current->title << endl;
        }
    }

    
    void previousSong() {
        if (current == NULL) {
            cout << "Playlist is empty.\n";
        } else if (current->prev == NULL) {
            cout << "Already at the first song.\n";
        } else {
            current = current->prev;
            cout << "Now playing: " << current->title << endl;
        }
    }

    
    void displayForward() {
        Song* temp = head;

        cout << "\nPlaylist (Forward):\n";
        while (temp != NULL) {
            cout << temp->title << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

   
    void displayBackward() {
        Song* temp = tail;

        cout << "\nPlaylist (Backward):\n";
        while (temp != NULL) {
            cout << temp->title << " -> ";
            temp = temp->prev;
        } 
        cout << "NULL\n";
    }

   
    void showCurrent() {
        if (current != NULL)
            cout << "Currently playing: " << current->title << endl;
        else
            cout << "Playlist is empty.\n";
    }

    ~Playlist() {
        Song* temp = head;

        while (temp != NULL) {
            Song* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    Playlist playlist;

    playlist.addSong("Finding her");
    playlist.addSong("Perfect");
    playlist.addSong("Bairan");
    playlist.addSong("Khat");

    playlist.displayForward();
    playlist.displayBackward();

    playlist.showCurrent();

    playlist.nextSong();      
    playlist.nextSong();      
    playlist.previousSong();  
    playlist.previousSong();  

    return 0;
}
