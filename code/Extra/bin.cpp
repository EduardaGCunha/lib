//Estruturas
signed main(){
    int n = 10;
    vector<int> v(n, 1);
    int x = 1;
	auto it = lower_bound(v.begin(), v.end(), x); //msm coisa com upperbound
    if(it != v.end()){

    }
}

void sets() {
	set<int> s;
	s.insert(1);                 // [1]
	s.insert(4);                 // [1, 4]
	s.insert(2);                 // [1, 2, 4]
	s.insert(1);                 // does nothing because 1's already in the set
	cout << s.count(1) << endl;  // 1
	s.erase(1);                  // [2, 4]
	cout << s.count(5) << endl;  // 0
	s.erase(0);                  // does nothing because 0 wasn't in the set
	s.insert(6);                 // [2, 4, 6]

	// Outputs 2, 4, and 6 separated by spaces
	for (int element : s) { cout << element << " "; }

    set<int> s;
    s.insert(1);                        // [1]
    s.insert(14);                       // [1, 14]
    s.insert(9);                        // [1, 9, 14]
    s.insert(2);                        // [1, 2, 9, 14]
    cout << *s.upper_bound(7) << '\n';  // 9
    cout << *s.upper_bound(9) << '\n';  // 14
    cout << *s.lower_bound(5) << '\n';  // 9
    cout << *s.lower_bound(9) << '\n';  // 9
    cout << *s.begin() << '\n';         // 1
    auto it = s.end();
    cout << *(--it) << '\n';    // 14
    s.erase(s.upper_bound(6));  // [1, 2, 14]
}

void hashsets() {
	unordered_set<int> s;
	s.insert(1);                 // {1}
	s.insert(4);                 // {1, 4}
	s.insert(2);                 // {1, 2, 4}
	s.insert(1);                 // does nothing because 1's already in the set
	cout << s.count(1) << endl;  // 1
	s.erase(1);                  // {2, 4}
	cout << s.count(5) << endl;  // 0
	s.erase(0);                  // does nothing because 0 wasn't in the set
	s.insert(6);                 // {2, 4, 6}

	// Outputs 6, 2, and 4 separated by spaces (not in sorted order)
	for (int element : s) { cout << element << " "; }
}

void maps() {
	map<int, int> m;
	m[1] = 5;                    // [(1, 5)]
	m[3] = 14;                   // [(1, 5); (3, 14)]
	m[2] = 7;                    // [(1, 5); (2, 7); (3, 14)]
	m[0] = -1;                   // [(0, -1); (1, 5); (2, 7); (3, 14)]
	m.erase(2);                  // [(0, -1); (1, 5); (3, 14)]
	cout << m[1] << endl;        // 5
	cout << m.count(7) << endl;  // 0
	cout << m.count(1) << endl;  // 1
	cout << m[2] << endl;        // 0
    map<int, int> m;
    m[3] = 5;     // [(3, 5)]
    m[11] = 4;    // [(3, 5); (11, 4)]
    m[10] = 491;  // [(3, 5); (10, 491); (11, 4)]
    cout << m.lower_bound(10)->first << " " << m.lower_bound(10)->second << '\n';  // 10 491
    cout << m.upper_bound(10)->first << " " << m.upper_bound(10)->second << '\n';  // 11 4
    m.erase(11);  // [(3, 5); (10, 491)]
    if (m.upper_bound(10) == m.end()) {
        cout << "end" << endl;  // Prints end
    }
}

void multisets(){
    //Using ms.erase(val) erases all instances of val from the multiset. 
    //To remove one instance of val, use ms.erase(ms.find(val))!
    multiset<int> ms;
    ms.insert(1);                  // [1]
    ms.insert(14);                 // [1, 14]
    ms.insert(9);                  // [1, 9, 14]
    ms.insert(2);                  // [1, 2, 9, 14]
    ms.insert(9);                  // [1, 2, 9, 9, 14]
    ms.insert(9);                  // [1, 2, 9, 9, 9, 14]
    cout << ms.count(4) << '\n';   // 0
    cout << ms.count(9) << '\n';   // 3
    cout << ms.count(14) << '\n';  // 1
    ms.erase(ms.find(9));
    cout << ms.count(9) << '\n';  // 2
    ms.erase(9);
    cout << ms.count(9) << '\n';  // 0
}
