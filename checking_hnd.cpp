bool isSequentialGroup(vector<string> cards){
	set<string > symbols;
	vector<string > nonJoker;
	int countOfJokers = 0;
	for(auto v:cards){
		if(v.substr(1,v.size())=="j") countOfJokers++;
		else {
			symbols.insert(v.substr(1,v.size()));
			nonJoker.push_back(v);
		}
	}
	if((int)symbols.size()>1)
		return false;
	if(nonJoker.size() == 1)
		return countOfJokers >= 2;
	int cardsCount = cards.size();
	vector<int > cardExist(14,false);
	vector<int > rangeOfExistance(14,0);
	for(auto card : nonJoker){
		cardExist[Rank[string(1,card[0])]] = 1;
	}
	for(int i=1;i<=13;i++) rangeOfExistance[i] = rangeOfExistance[i-1]+cardExist[i];
	for(int i=1;i<=13;i++){
		int countOfCardsInRange,countOfMissedCards;
		int left= i, right = i + cardsCount - 1;
		if(right <=13){
			countOfCardsInRange = rangeOfExistance[right]-rangeOfExistance[left-1];
		}else{
			countOfCardsInRange = rangeOfExistance[13]-rangeOfExistance[left-1];
			countOfCardsInRange += rangeOfExistance[right%13];
		}
		countOfMissedCards = cardsCount - countOfCardsInRange;
		if(countOfMissedCards <= countOfJokers){
			cout<<i<<' '<<countOfMissedCards<<endl;
			return true;
		}
	}
	return false;
}
bool isValid(vector<string> cards){
	return isSequentialGroup(cards) || isRankGroup(cards);
}
void solve(){
	for(int i=2;i<10;i++)Rank[to_string(i)]=i;
	Rank["10"]=10;
	Rank["J"]=11;
	Rank["Q"]=12;
	Rank["K"]=13;
	Rank["A"]=1;

	vector<string > cards = {"Kh", "Ah", "2h"};
	// {"Ac","2c","Jc", "Qc","1j"}; 
	// {"Qd", "Kd", "Ad"};
	// {"5h", "4h", "3h"};
	// {"2h", "5h", "6h", "7h", "8h","1j","2j"};
	cout<<isValid(cards)<<endl;
}