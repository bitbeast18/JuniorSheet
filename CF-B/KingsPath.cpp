    /*
    *   1. What was the key concept?
    *   2. What mistake did I make? (if any)
    *   3. Thing to remember from now on.
    */

   // overcomplicated this solution.
   // just push all points in the set and do normal bfs.
   // too slow implementation.

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <map>
    #include <set>
    #include <queue>
    #include <iomanip>
    #include <string>
    #include <cmath>
    using namespace std;

    #define endl '\n'
    #define INF 0x3f3f3f3f;
    #define INFL 0x3f3f3f3f3f3f3f3f;
    #define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
    #define PRECISE cout << fixed << setprecision(9)

    using ll = long long int;
    using ld = long double;

    const int MOD = 1e9 + 7;
    const int N = 1e6 + 5;


    int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

    map<ll, vector<pair<ll, ll>>> cnt;

    bool valid(pair<ll, ll> a){

        if (cnt.count(a.first)){

            for(auto range: cnt[a.first]){
                if (a.second >= range.first and a.second <= range.second) return true;
            }

            return false;

        } else return false;

    }

    ll dist(pair<ll, ll> s, pair<ll, ll> t){


        queue<pair<pair<int, int>, int>> up;
        set<pair<int, int>> vis;

        up.push({s, 0});
        vis.insert(s);

        while(!up.empty()){

            auto cur = up.front();
            up.pop();

            // process.
            if (cur.first.first == t.first and cur.first.second == t.second){
                return cur.second;
            }

            vis.insert(cur.first);

            for(int i=0; i<8; i++){

                pair<ll, ll> nex;
                nex.first = cur.first.first + dx[i];
                nex.second = cur.first.second + dy[i];

                if (!vis.count(nex) and valid(nex)){
                    up.push({nex, cur.second + 1});
                }
            }
        }

        return -1;
    }

    int main(){
        // code here.

        pair<ll, ll> s, t;
        cin >> s.first >> s.second >> t.first >> t.second;

        int w;
        cin >> w;

        while(w--){
            ll r, x, y;
            cin >> r >> x >> y;

            cnt[r].push_back({x, y});
        }

        cout << dist(s, t) << endl;

        return 0;
    }

    // Check the corner cases. (n = 1).
    // Check overflows. (int vs ll).
    // Be consistent.