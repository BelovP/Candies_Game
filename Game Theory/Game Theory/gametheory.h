#ifndef GAMETHEORY_H
#define GAMETHEORY_H

#include <QtGui/QWidget>
#include "ui_gametheory.h"
#include "QTimer"
#include "QString"
#include <vector>
using std::vector;
class GameTheory : public QWidget
{
	Q_OBJECT

	int current_active_player, ai_player, number_of_candies, available_candies, number_of_unselected_heaps, heap_buttons_to_be_pressed, ok_buttons_to_be_pressed;
	bool game_finished, is_start_of_the_game;
	vector<int> candies_in_heap;
	QTimer *start_timer, *timer_to_watch_AI;

private:
	Ui::GameTheoryClass ui;

	bool CheckInitialNumber(QString str)
	{
		bool ok = 1;
		if (str.isEmpty())
			return false;
		int num = str.toInt(&ok, 10);
		if (!ok)
			return false;
		if (num >= 3 && num <= 10000)
			return true;
		return false;
	}
	void TurnOffHeapButtons()
	{
		ui.heap_button_1->setEnabled(false);
		ui.heap_button_2->setEnabled(false);
		ui.heap_button_3->setEnabled(false);
	}
	void TurnOffOkButtons()
	{
		ui.ok_button_1->setEnabled(false);
		ui.ok_button_2->setEnabled(false);
		ui.ok_button_3->setEnabled(false);
	}
	void TurnOnHeapButtons()
	{
		ui.heap_button_1->setEnabled(true);
		ui.heap_button_2->setEnabled(true);
		ui.heap_button_3->setEnabled(true);
	}
	void TurnOnOkButtons()
	{
		ui.ok_button_1->setEnabled(true);
		ui.ok_button_2->setEnabled(true);
		ui.ok_button_3->setEnabled(true);
	}
	bool IsLosingMod(int checked_index)
	{
		if (candies_in_heap[checked_index] % 6 == 1 || candies_in_heap[checked_index] % 6 == 2)
			return true;
		return false;
	}
	size_t SelectHeapForAI()
	{
		size_t result_index = 4;
		for (size_t index = 0; index < 3; ++index)
			if (result_index == 4 || (IsLosingMod(result_index) && (!IsLosingMod(index) || candies_in_heap[index] > candies_in_heap[result_index])) 
				|| (!IsLosingMod(result_index) && !IsLosingMod(index) && candies_in_heap[index] > candies_in_heap[result_index]))
				result_index = index;
		return result_index;
	}
	bool IsPlayerWon(int candies_to_play)
	{
		if (candies_to_play < 3)
			return true;
		return false;
	}
	void PlayerWon()    
	{
		game_finished = true;
		TurnOffHeapButtons();
		TurnOffOkButtons();
		ui.informer->setText(QString("Congratulations! You won!"));
		//exit(0);
	}
	bool IsAIWon(int candies_to_play)
	{
		if (candies_to_play < 3)
			return true;
		return false;
	}
	void AIWon()
	{
		game_finished = true;
		TurnOffHeapButtons();
		TurnOffOkButtons();
		ui.informer->setText(QString("You lost... :("));
		//exit(0);
	}
	void DeleteHeaps(size_t heap_to_stay)
	{
		QString indices_of_del_heaps, str;
		if (heap_to_stay != 0)
		{
			ui.heap_1->display(0);
			str.setNum(1);
			indices_of_del_heaps += str;
			candies_in_heap[0] = 0;
		}
		if (heap_to_stay != 1)
		{
			ui.heap_2->display(0);
			str.setNum(2);
			if (!indices_of_del_heaps.isEmpty())
				indices_of_del_heaps += QString(" and ");

			indices_of_del_heaps += str;
			candies_in_heap[1] = 0;
		}
		if (heap_to_stay != 2)
		{
			ui.heap_3->display(0);
			str.setNum(3);
			if (!indices_of_del_heaps.isEmpty())
				indices_of_del_heaps += QString(" and ");

			indices_of_del_heaps += str;
			candies_in_heap[2] = 0;
		}
		ui.informer->setText(QString("AI deleted ") + indices_of_del_heaps + QString(" heaps"));
	}
	void SeparateCandies()
	{
		bool separated = false;
		if (available_candies % 6 == 0)
		{
			separated = true;
			candies_in_heap[0] = 2;
			candies_in_heap[1] = 2;
			candies_in_heap[2] = available_candies - 4;
		}
		if (available_candies % 6 == 3)
		{
			separated = true;
			candies_in_heap[0] = 1;
			candies_in_heap[1] = 1;
			candies_in_heap[2] = available_candies - 2;
		}
		if (available_candies % 6 == 4)
		{
			separated = true;
			candies_in_heap[0] = 1;
			candies_in_heap[1] = 2;
			candies_in_heap[2] = available_candies - 3;
		}
		if (available_candies % 6 == 5)
		{
			separated = true;
			candies_in_heap[0] = 2;
			candies_in_heap[1] = 2;
			candies_in_heap[2] = available_candies - 4;
		}

		if (!separated)
		{
			candies_in_heap[0] = 1;
			candies_in_heap[1] = 1;
			candies_in_heap[2] = available_candies - 2;
		}

		ui.heap_1->display(candies_in_heap[0]);
		ui.heap_2->display(candies_in_heap[1]);
		ui.heap_3->display(candies_in_heap[2]);
		if (ui.informer->text() != QString("Select a player and choose the number of candies"))
			ui.informer->setText(ui.informer->text() + QString(" and separated last candies"));
		else
			ui.informer->setText(QString("AI separated the candies"));
	}
	void AITurn()
	{
		if (game_finished)
			return;

		TurnOffHeapButtons();
		TurnOffOkButtons();
		if (!is_start_of_the_game)
		{
			size_t heap_to_play = SelectHeapForAI();
		
			if (IsPlayerWon(candies_in_heap[heap_to_play]))
				PlayerWon();									//TODO
		
			if (game_finished)
				return;

			DeleteHeaps(heap_to_play);

			number_of_candies = candies_in_heap[heap_to_play];
			available_candies = number_of_candies;
			candies_in_heap[heap_to_play] = 0;
		}
		is_start_of_the_game = false;
		SeparateCandies();
		timer_to_watch_AI->start(3000);
	}
	bool IsValidNumberOfCandies(QString str_number_of_candies)
	{
		if (str_number_of_candies.isEmpty())
			return false;
		
		bool conversion_ok = 1;
		int candies = str_number_of_candies.toInt(&conversion_ok, 10);
		
		if (!conversion_ok)
			return false;

		if (candies > available_candies - number_of_unselected_heaps + 1 || candies <= 0 || (number_of_unselected_heaps == 1 && candies != available_candies))
			return false;
		return true;
	}
	void GameMainCycle()
	{
		while(true)
		{

		}
	}
public:
	GameTheory(QWidget *parent = 0, Qt::WFlags flags = 0);
	~GameTheory();

public slots:
	void SwitchTurnToPlayer()
	{
		ui.informer->setText(QString("Now you have to delete any 2 heaps of candies"));

		heap_buttons_to_be_pressed = 2;
		TurnOnHeapButtons();
		timer_to_watch_AI->stop();
	}
	void StartGame()
	{
		start_timer->stop();
		QString str_number_of_candies;
		str_number_of_candies.setNum(number_of_candies);
		
		if(ai_player == 2)
		{
			TurnOffHeapButtons();
			TurnOnOkButtons();
			ui.informer->setText(QString("Separate ") + str_number_of_candies + QString (" candies in 3 heaps"));
		}
		else
		{

			AITurn();
		}
		//GameMainCycle();
	}
	void HeapButtonClicked()
	{
		QPushButton * clicked_button = qobject_cast<QPushButton *>(sender());

		if (clicked_button == ui.heap_button_1)
		{
			available_candies -= candies_in_heap[0];
			number_of_candies -= candies_in_heap[0];
			candies_in_heap[0] = 0;
			ui.heap_1->display(0);
			heap_buttons_to_be_pressed--;
			ui.heap_button_1->setEnabled(false);
		}
		if (clicked_button == ui.heap_button_2)
		{
			available_candies -= candies_in_heap[1];
			number_of_candies -= candies_in_heap[1];
			candies_in_heap[1] = 0;
			ui.heap_2->display(0);
			heap_buttons_to_be_pressed--;
			ui.heap_button_2->setEnabled(false);
		}
		if (clicked_button == ui.heap_button_3)
		{
			available_candies -= candies_in_heap[2];
			number_of_candies -= candies_in_heap[2];
			candies_in_heap[2] = 0;
			ui.heap_3->display(0);
			heap_buttons_to_be_pressed--;
			ui.heap_button_3->setEnabled(false);
		}

		if (heap_buttons_to_be_pressed == 0)
		{
			if (IsAIWon(available_candies))
			{
				AIWon();									//TODO
				if (game_finished)
					return;
			}

			ui.heap_1->display(0);
			ui.heap_2->display(0);
			ui.heap_3->display(0);
			TurnOffHeapButtons();
			TurnOnOkButtons();

			QString str_number_of_candies;
			str_number_of_candies.setNum(number_of_candies);
			ui.informer->setText(QString("Separate ") + str_number_of_candies + QString (" candies in 3 heaps"));
			ok_buttons_to_be_pressed = 3;
			number_of_unselected_heaps = 3;
		}
	}
	void CandiesChosen()
	{
		QString str_initial_number = ui.initial_candies->text();

		if (CheckInitialNumber(str_initial_number))
		{
			number_of_candies = str_initial_number.toInt();
			available_candies = number_of_candies;

			if (ui.radioButton->isChecked())
				ai_player = 2;
			else
				ai_player = 1;

			ui.ok_candies->setEnabled(false);
			ui.ok_candies->setVisible(false);
			ui.radioButton->setVisible(false);
			ui.radioButton_2->setVisible(false);
			ui.initial_candies->setVisible(false);
			start_timer->start(10);
		}
	}
	void OkButtonClicked()
	{
		QPushButton * clicked_button = qobject_cast<QPushButton *>(sender());
		QString str_number_in_heap;
		int number_in_heap;
		bool ok;

		is_start_of_the_game = false;

		if (clicked_button == ui.ok_button_1)
		{
			str_number_in_heap = ui.number_1->text();
			if (IsValidNumberOfCandies(str_number_in_heap))
			{
				number_in_heap = str_number_in_heap.toInt(&ok, 10);
				candies_in_heap[0] = number_in_heap;
				available_candies -= number_in_heap;
				--number_of_unselected_heaps;
				ui.ok_button_1->setEnabled(false);
				ui.heap_1->display(number_in_heap);
			}
		}
		if (clicked_button == ui.ok_button_2)
		{
			str_number_in_heap = ui.number_2->text();
			if (IsValidNumberOfCandies(str_number_in_heap))
			{
				number_in_heap = str_number_in_heap.toInt(&ok, 10);
				candies_in_heap[1] = number_in_heap;
				available_candies -= number_in_heap;
				--number_of_unselected_heaps;
				ui.ok_button_2->setEnabled(false);
				ui.heap_2->display(number_in_heap);
			}
		}
		if (clicked_button == ui.ok_button_3)
		{
			str_number_in_heap = ui.number_3->text();
			if (IsValidNumberOfCandies(str_number_in_heap))
			{
				number_in_heap = str_number_in_heap.toInt(&ok, 10);
				candies_in_heap[2] = number_in_heap;
				available_candies -= number_in_heap;
				--number_of_unselected_heaps;
				ui.ok_button_3->setEnabled(false);
				ui.heap_3->display(number_in_heap);
			}
		}
		if (number_of_unselected_heaps == 0)
		{
			AITurn();
		}
	}

};

#endif // GAMETHEORY_H
