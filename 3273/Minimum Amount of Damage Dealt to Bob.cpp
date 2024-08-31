// Minimum Amount of Damage Dealt to Bob.cpp

// You are given an integer power and two integer arrays damage and health, both having length n.

// Bob has n enemies, where enemy i will deal Bob damage[i] points of damage per second while they are alive (i.e. health[i] > 0).

// Every second, after the enemies deal damage to Bob, he chooses one of the enemies that is still alive and deals power points of damage to them.

// Determine the minimum total amount of damage points that will be dealt to Bob before all n enemies are dead.



typedef pair<long double, int> pdi;
typedef long long ll;

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        priority_queue<pdi> pq; 
        ll td = 0;
        for(int i=0; i<health.size(); i++) {
            ll time = ceil((1.0*health[i])/(1.0*power));
            long double dps = (double)damage[i]/(double)time;
            // cout<<dps<<endl;
            td += damage[i];
            pq.push({ dps, i });
        }

        ll total_damage = 0;
        while(!pq.empty()) {
            int index = pq.top().second;
            ll t = ceil((1.0 * health[index])/(1.0*power));
            total_damage += (td * t);
            td -= damage[index];
            pq.pop();
        }

        return total_damage;
    }
};