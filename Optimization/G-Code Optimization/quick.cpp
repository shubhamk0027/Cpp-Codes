#include<bits/stdc++.h>
#define pff pair<float,float>
#define gcode vector<pff>
#define x first
#define y second
using namespace std;



string penUp  ="M300 S50.00 (pen up)";
string penDown="M300 S30.00 (pen down)";
string hold   ="G4 P150 (wait 150ms)";
string comment="(Polyline consisting of 1 segments.)";



vector<string> startlines;
vector<gcode> segments;
vector<string> endlines;
vector<int> finalOrder;
int n;



pff getCoordinate(string & line){
    int i=4;
    while(line[i]!=' ') {
        i++;
    }
    // cerr<<line.substr(4,i-4)<<" ";
    int j=i+2;
    while(line[j]!=' ') {
        j++;
    }
    // cerr<<line.substr(i+2,j-i-2)<<"\n";
    return {
        stof(line.substr(4,i-4)),
        stof(line.substr(i+2,j-i-2))
    };
}




void getInput(){

    string line;
    gcode temp;

    // cerr<<"HEADERS\n";
    while(getline(cin,line)){
        if(line.size()==1) {
            break;
        }
        startlines.push_back(line);
        // cerr<<line<<"\n";
    }

    // cerr<<"COORDINATES\n";
    while(getline(cin,line)){
        if(line.size()==1) {
            if(temp.size()==0) {
                break;
            }
            assert(temp.size()>0);
            segments.push_back(temp);
            temp.clear();
            continue;
        }
        if(line[0]!='G' || line[1]!='1') {
            continue;
        }
        temp.push_back(getCoordinate(line));
        // cerr<<line<<"\n";
    }

    // cerr<<"\nEND LINES\n";
    while(getline(cin,line)){
        endlines.push_back(line);
        // cerr<<line<<"\n";
    }
}




double distance(pff &p1, pff & p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}




void optimize(){

    int min_at=0;

    for(int i=1;i<n;i++){
        if(segments[min_at][0]>segments[i][0]){
            min_at=i;
        }
    }    


    finalOrder.push_back(min_at);
    vector<bool> vis(n+1,0);
    vis[min_at]=1;
    
    while(finalOrder.size()<n){

        double mindist=1e15;
        
        auto prev= segments[finalOrder.back()].back();
        bool to_reverse=0;

        for(int i=0;i<n;i++) if(!vis[i]){
            double dist= distance(prev,segments[i][0]);
            if(dist<mindist){
                min_at=i;
                mindist=dist;
                to_reverse=0;
            }
            dist= distance(prev,segments[i].back());
            if(dist<mindist){
                min_at=i;
                mindist=dist;
                to_reverse=1;
            }
        }

        finalOrder.push_back(min_at);
        vis[min_at]=1;
        if(to_reverse){
            reverse(segments[min_at].begin(),segments[min_at].end());
        }
    }
    
}




void printCoordinates(){

    cerr<<"\nOld Coordinates\n";
    for(int i=0;i<n;i++){
        cerr<<i<<":\t[";
        cerr<<segments[i][0].x<<","<<segments[i][0].y<<"]\t[";
        cerr<<segments[i].back().x<<","<<segments[i].back().y<<"]\t";
        cerr<<segments[i].size()<<"\n";
    }

    cerr<<"\nNew Coordinates\n";
    for(auto &i:finalOrder){
        cerr<<i<<":\t[";
        cerr<<segments[i][0].x<<","<<segments[i][0].y<<"]\t[";
        cerr<<segments[i].back().x<<","<<segments[i].back().y<<"]\t";
        cerr<<segments[i].size()<<"\n";
    }

}


void generateCode(){
    
    printf("(MODIFIED CODE)\n");
    for(auto line : startlines) {
        printf("%s\n",line.c_str());
    }
    
    printf("\n");

    for(auto &x: finalOrder){
        auto& seg=segments[x];
        printf("%s\n",comment.c_str());
        printf("G1 X%.2f Y%.2f F3500.00\n",seg[0].x,seg[0].y);
        printf("%s\n",penDown.c_str());
        printf("%s\n",hold.c_str());
        for(int i=1;i<seg.size();i++){
            printf("G1 X%.2f Y%.2f F3500.00\n",seg[i].x,seg[i].y);
        }
        printf("%s\n",penUp.c_str());
        printf("%s\n\n",hold.c_str());
    }

    for(auto line : endlines){
        printf("%s\n",line.c_str());
    }
}

void analyze(){

    double before=0;
    pff prev={0.0,0.0};
    for(int i=0;i<n;i++){
        for(auto &pp: segments[i]){
            double dist=sqrt(distance(prev,pp));
            before=before+dist;
            prev=pp;
        }
    }

    double after=0;
    prev={0,0};
    for(auto i: finalOrder){
        for(auto &pp: segments[i]){
            after+=sqrt(distance(prev,pp));
            prev=pp;
        }
    }
    cerr<<"\nDISTANCE MOVED BEFORE: "<<before<<"\n";
    cerr<<"DISTANCE MOVED AFTER: "<<after<<"\n";
    double red = ((before-after)/before)*100;
    cerr<<"EXPECTED TIME REDUCTION BY "<<red<<"% \n";
}

int main(){

    cerr<<"\nGetting Input...\n";
    getInput();
    
    n=segments.size();
    cerr<<"\nOptimizing Code...\n";
    optimize();
    
    // printCoordinates();
    
    cerr<<"\nGenerating New Code...\n";
    generateCode();

    cerr<<"\nAnalyzing...\n";
    analyze();

    return 0;
}