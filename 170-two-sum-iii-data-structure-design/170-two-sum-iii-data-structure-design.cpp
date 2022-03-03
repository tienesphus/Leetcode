class TwoSum {
public:
    map<long long,long long> m;
    TwoSum() {
        
    }
    
    void add(int number) {
        if (m.find(number) == m.end())
            m.insert(make_pair(number, 1));
        else m.find(number)->second++;
    }
    
    bool find(int value) {
        for (auto& e : m)
        {
            long complement = value - e.first;
            auto it_find = m.find(complement);
            
            if (it_find != m.end())
            {
                if (it_find != m.find(e.first))
                    return true;
                else if (m.find(e.first)->second > 1)
                    return true;
            }
            
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */