char choice;
bool cont=0;

void GuessSize(){     
    
        if ((choice=='S'&& nextcard.getRank()<currentcard.getRank())){
            cont =1;
        }

        else if ((choice=='S' && nextcard.getRank()>currentcard.getRank())){
            cont=0;
        }

        else if ((choice=='L' && nextcard.getRank()>currentcard.getRank())){
			  cont =1;
        }

        else if ((choice=='h' && (nextcard.getRank()<currentcard.getRank()))){
			  cont =0;
        }

        else if ((((choice=='h') || (choice=='l')) && (currentcard.getRank()==nextcard.getRank()))){
            cont =0;
        }

        //else {
            //i--;
        //}

	return cont;
	

void GuessColour(){     

        if ((choice=='R'&& (nextcard.getSuit()=='2'||nextcard.getSuit()=='4'))){
            cont =1;
        }

        else if ((choice=='R'&& (nextcard.getSuit()=='1'||nextcard.getSuit()=='3'))){
            cont=0;
        }

        else if ((choice=='B'&& (nextcard.getSuit()=='1'||nextcard.getSuit()=='3'))){
			  cont =1;
        }

        else if ((choice=='B'&& (nextcard.getSuit()=='2'||nextcard.getSuit()=='4'))){
			  cont =0;
        }

	return cont;
	

void vsComputer(){
	srand (time(NULL));
	int r;
	int player=1;
	if(player%2==1)
	player=1;
	else
	player=2;
	if (player=='2'){
		r = rand()%2;
		if ((2<=card<=12)||(15<=card<=25)||(28<=card<=38)||(41<=card<=51)){

			if r == '0'
			choice == 'L';
			else 
			choice =='S';
			cout << choice << endl;
			GuessSize();
		}
		else{
			if r == '0'
			choice == 'R';
			else 
			choice =='B';
			cout << choice<<endl;
			GuessColour();
		}
		if cont =='1'
		player ++;
	}
	else if (player=='1'){
		if ((2<=card<=12)||(15<=card<=25)||(28<=card<=38)||(41<=card<=51)){
			cout <<"Press 'L' if you think the next card will be larger"<<endl;
    		cout <<"Press 'S' if you think the next card will be smaller"<<endl;
			cin >> choice>>endl;
			GuessSize();
		}
		else{
			cout <<"Press 'R' if you think the next card will be red"<<endl;
    		cout <<"Press 'B' if you think the next card will be black"<<endl;
			cin >> choice >> endl;
			GuessColour();
		}
		if cont =='1'{
		player++;
		money++;
		score++;
	}
void single(){
		if ((2<=card<=12)||(15<=card<=25)||(28<=card<=38)||(41<=card<=51)){
			cout <<"Press 'L' if you think the next card will be larger"<<endl;
    		cout <<"Press 'S' if you think the next card will be smaller"<<endl;
			cin >> choice>>endl;
			GuessSize();
		else
			cout <<"Press 'R' if you think the next card will be red"<<endl;
    		cout <<"Press 'B' if you think the next card will be black"<<endl;
			cin >> choice >> endl;
			GuessColour();
		if (cont=='1'){
		money++;
		score++;
		}
	
