int main() {
    int N, Q; 
	vector <string> baseStrings;
	vector <int> queryStrings;

	cin >> N;
	int loops = 0;
	int inBaseStrings = 1;
	string input;

	while(loops < N){
		cin >> input;
		for(int i = 0; i < baseStrings.size(); i++){
			if(input == baseStrings[i]){
				queryStrings[i]++;
				inBaseStrings = 0; //set flag
			}
		}
		if(inBaseStrings == 1){ //we need to add it into queryString
			baseStrings.push_back(input);
			queryStrings.push_back(1);
		}
		inBaseStrings = 1; //reset flag
		loops++;
	}//for(int i = 0; i < queryStrings.size(); i++){cout << queryStrings[i] << endl;}

	cin >> Q;
	loops = 0;
	inBaseStrings = 1;
	vector <int> tally;

	while(loops < Q){
		cin >> input;
		for(int i = 0; i < baseStrings.size(); i++){
			if(input == baseStrings[i]){
				tally.push_back(queryStrings[i]);
				inBaseStrings = 0; //set flag
			}
		}
		if(inBaseStrings == 1){
			tally.push_back(0);
		}
		inBaseStrings = 1;
		loops++;
	}
	
	for(int i = 0; i < tally.size(); i++){
		cout << tally[i] << endl;
	}

    return 0;
}