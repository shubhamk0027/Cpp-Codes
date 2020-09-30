#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
typedef vector<int> vi;
typedef vector< vector<int> > vii;
typedef vector<string> vs;
typedef unordered_map<int, int> uii;
typedef unordered_map<char, int> uci;
typedef unordered_map<string, int> usi;
typedef vector< pair<int, int> > vpii;
typedef vector< pair<string, string> > vpss;
typedef pair< int, char > pic;
typedef vector<pic> vpic;
typedef set< string > ss;
typedef set< int > si;
typedef set< char > sc;

bool comparison(pic &a, pic &b) {
    if(a.first < b.first) {
        return true;
    }
    return false;
}

bool hasConsecutivity(vpic charData) {
    for(int i = 0; i < charData.size()-1; i++) {
        if((charData[i+1].first - charData[i].first) != 1) {
            return false;
        }
    }
    return true;
}

bool areOfSameDeck(vpic charData) {
    for(int i = 0; i < charData.size()-1; i++) {
        if(charData[i].second != charData[i+1].second) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vpic charData;
    char face, deck;
    int faceVal;
    pic _ace;
    for(int i = 0; i < 5; i++) {

        cin>>face>>deck;
        if(face == 'A') {
            _ace.first = -1;
            _ace.second = deck;
            continue;
        }

        if(face >= '2' && face <= '9') {
            faceVal = face - '0';
        }

        else {
            switch (face)
            {
            case 'T':
                faceVal = 10;
                break;
            case 'J':
                faceVal = 11;
                break;
            case 'Q':
                faceVal = 12;
                break;     
            case 'K':
                faceVal = 13;
                break;
            default:
                break;
            }
        }

        charData.push_back(make_pair(faceVal, deck));

    }

    if(areOfSameDeck(charData)) {
        sort(charData.begin(), charData.end(), comparison);
        if(hasConsecutivity(charData)) {
            if(charData.size() == 4 && (charData[0].first == 2 || charData[3].first == 13)) {
                cout<<"YES";
            }

            else if(charData.size() == 5) {
                cout<<"YES";
            }

            else {
                cout<<"NO";
            }
        }

        else {
            cout<<"NO";
        }
    }

    else {
        cout<<"NO";
    }
    
    return 0;

}