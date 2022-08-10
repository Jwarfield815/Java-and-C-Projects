/*
	Header file for class die
*/

class die {
	public:
		die();
		// constructor
		// sets the default number rolled by a die to 1

		void roll();
		// function to roll a die
		// this function uses a random number generator to randomely
		// generate a number between 1 and 6, and stores the number
		// in the instance variable num

		int getNum() const;
		// function to return the number on te top face of the die
		// returns the value of the instance variable num

	private:
		int num;
};