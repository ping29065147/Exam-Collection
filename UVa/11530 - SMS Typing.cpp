#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, a, total, t;
    cin >> n;
    cin.ignore();
    string line;

    for(t=1; t<=n; t++){

        getline(cin, line);

        total = 0;
        for(a=0; a<line.size(); a++){
            if (line[a]=='a' || line[a]=='d' || line[a]=='g' || line[a]=='j' || line[a]=='m' || line[a]=='p' || line[a]=='t' || line[a]=='w' || line[a]==' ')
                total++;
            else if (line[a]=='b' || line[a]=='e' || line[a]=='h' || line[a]=='k' || line[a]=='n' || line[a]=='q' || line[a]=='u' || line[a]=='x')
                total += 2;
            else if (line[a]=='c' || line[a]=='f' || line[a]=='i' || line[a]=='l' || line[a]=='o' || line[a]=='r' || line[a]=='v' || line[a]=='y')
                total += 3;
            else
                total += 4;
        }

        cout << "Case #" << t << ": " << total << endl;
    }

    return 0;
}
