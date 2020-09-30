bool search(vector<vector<int>> vec,int toSearch){
	int i=0, j=vec[0].size()-1;
	while(i!=n-1 && j!=0){
		if(vec[i][j]==toSearch) return true;
		if(vec[i][j]>toSearch) j--;
		else i++;  
	}
	return false;
}