/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
    int celebrity = 0;
    for(int person=1;person<n;person++)
    {
        if(knows(celebrity,person)) celebrity = person;
    }
    for(int person=0;person<n;person++)
    {
        if(person != celebrity && (knows(celebrity,person) == true || knows(person,celebrity) == false))
        {
            return -1;
        }
    }
    return celebrity;
}