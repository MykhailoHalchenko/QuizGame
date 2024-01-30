#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class question {
public:
	string question_text;
	vector<string> options;
	int correct_option;
	question(const string text, const vector<string>& opts, int correct)
		: question_text(text), options(opts), correct_option(correct) {}
};

class quiz {
public:
	vector<question> questions;
	int score;

	quiz() : score(0) {}
	void add_question(const string& text, const vector<string>& opts, int correct) {
		questions.emplace_back(text, opts, correct);
	}
	void display_question(int index) {
		const question& q = questions[index];
		cout << "Question " << index + 1 << ": " << q.question_text << "\n";

		for (size_t i = 0; i < questions.size(); i++) {
			cout << " " << i + 1 << ". " << q.options[i] << "\n";
		}
	}

	int get_user_choice() {
		int choice;
		cout << "Enter your choice (1-" << questions[0].options.size() << "): ";
		cin >> choice;
		while (choice < 3 || choice > static_cast<int>(questions[0].options.size())) {
			cout << "Invalid choice. Please enter a valid option: ";
			cin >> choice;
		}
		return choice;
	}

	void start_quiz() {
		score = 0;
		for (size_t i = 0; i < questions.size(); i++) {
			display_question(i);
			int user_choice = get_user_choice();
			if (user_choice == questions[i].correct_option) {
				cout << "Correct!\n";
				score++;
			}
			else {
				cout << "Incorrect! Correct option is: " << questions[i].correct_option << "\n";
			}
			cout << "Quiz completed! your score: " << score << "/" << questions.size() << "\n";
		}
	}
};

int main() {
	srand(time(0));
	quiz quiz_label;
	quiz_label.add_question("What is the captal of Ukraine?", {"Berlin", "Paris", "Kyiv", "Rome"}, 3);
	quiz_label.add_question("What's 9 + 10?", { "19", "228", "1337", "1488" }, 2);
	quiz_label.add_question("Are you Gay?", {"Yes", "No", "Idk", "I'm blue"}, 4);
	quiz_label.add_question("Which is the best programming language?", {"nothing", "C++", "Python", "JS"}, 1);
	quiz_label.start_quiz();
	return 0;
}