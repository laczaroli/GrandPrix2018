#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class sparseMatrix {
private:
  int row, column, value, next;
public:
  sparseMatrix() {
    this->row = 0;
    this->column = 0;
    this->value = 0;
    this->next = 0;
  }

  void addValue(int row, int column, int value, int next) {
    this->row = row;
    this->column = column;
    this->value = value;
    this->next = next;
  }

  int getRow() {
    return this->row;
  }

  int getColumn() {
    return this->column;
  }

  int getValue() {
    return this->value;
  }

  int getNext() {
    return this->next;
  }

  void setRow(int k) {
    this->row = k;
  }

  void setColumn(int k) {
    this->column = k;
  }

  void setValue(int k) {
    this->value = k;
  }

  void setNext(int k) {
    this->next = k;
  }
};

int main() {

  int k=2, u=3;
  int x = 0;
  cin >> k >> u;
  int n = 0;
  sparseMatrix temp;
  sparseMatrix* prevPos;
  sparseMatrix* prevNeg;
  vector<sparseMatrix> positives;
  vector<sparseMatrix> negatives;
  for(int i = 0; i < k; i++)
  {
    prevPos = NULL;
    prevNeg = NULL;
    for(int j = 0; j < u; j++)
    {
      cin >> n;

      if(n > 0) {
        temp.setRow(i);
        temp.setColumn(j);
        temp.setValue(n);
        positives.push_back(temp);
        if(prevPos == NULL)
        {
          prevPos = &positives[positives.size()-1];
        } else {
          prevPos->setNext(positives.size());
          prevPos = &positives[positives.size()-1];
        }

        cout << &positives[positives.size()-1] << " " << prevPos;
        x++;
      } else if(n < 0)
      {
        temp.setRow(i);
        temp.setColumn(j);
        temp.setValue(n);
        negatives.push_back(temp);
        if(prevNeg == NULL)
        {
          prevNeg = &temp;
        } else {
          prevNeg->setNext(negatives.size()-1);
          prevNeg = &temp;
        }
      }
    }
  }

  for(int i = 0; i < positives.size(); i++)
  {
    cout << positives[i].getRow() << " ";
    cout << positives[i].getColumn() << " ";
    cout << positives[i].getValue() << " ";
    cout << positives[i].getNext() << endl;
  }

  /*j
  int jk [k][u] = {
    {1,-2,2},
    {-2,-2,3}
  };

  jk[0][0] = 0;
  jk[0][1] = 1;
  jk[0][2] = -2;
  jk[1][0] = 4;
  jk[1][1] = -3;
  jk[1][2] = 0;*/

  /*sparseMatrix temp;

  vector<sparseMatrix> sp;
  vector<sparseMatrix> sn;

  for(int i = 0; i<k; i++)
  {
    for(int j = 0; j<u; j++)
    {
      if(jk[i][j] > 0)
      {
        temp.setRow(i);
        temp.setColumn(j);
        temp.setValue(jk[i][j]);
        sp.push_back(temp);
      } else if(jk[i][j] < 0)
      {
        temp.setRow(i);
        temp.setColumn(j);
        temp.setValue(jk[i][j]);
        sn.push_back(temp);
      }
    }
  }

  //Következő kiszámítása

  int tempCol = 0;

  for(int i = 0; i<sp.size(); i++)
  {
    for(int j = i+1; j<sp.size(); j++) //túlcsordulás lehetséges
    {
      if(sp[i].getColumn() == sp[j].getColumn())
      {
        sp[i].setNext(j+1);
        break;
      }
    }
  }

  for(int i = 0; i<sn.size(); i++)
  {
    for(int j = i+1; j<sn.size(); j++) //túlcsordulás lehetséges
    {
      if(sn[i].getColumn() == sn[j].getColumn())
      {
        sn[i].setNext(j+1);
        break;
      }
    }
  }

  for(int i = 0; i<sp.size(); i++)
  {
    cout <<
    "\nO: " << sp[i].getRow() <<
    "\nS: " << sp[i].getColumn() <<
    "\nÉ: " << sp[i].getValue() <<
    "\nK: " << sp[i].getNext() << endl;
  }

  for(int i = 0; i<sn.size(); i++)
  {
    cout <<
    "\nO: " << sn[i].getRow() <<
    "\nS: " << sn[i].getColumn() <<
    "\nÉ: " << sn[i].getValue() <<
    "\nK: " << sn[i].getNext() << endl;
  }
*/
  return 0;
}
