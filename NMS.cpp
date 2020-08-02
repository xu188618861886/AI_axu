
#include<vector> 

float iou(int x1, int x2, int y1, int y2, int x1_, int x2_, int y1_, int y2_)
{
    int X1 = std::max(x1, x1_);
    int Y1 = std::max(y1, y1_);
    int X2 = std::min(x2, x2_);
    int Y2 = std::min(y2, y2_));
    float I_area = (X2 - X1) * (Y2 - Y1);
    float U_area = ( (x2 - x1) * (y2 - y1) + (x2_ - x1_) * (y2_ - y1_) - I_area);
    float iou = I_area / U_area;
    return iou;
}

bool sort_cmp(std::vector n1, std::vector n2)
{
    return (n1[4] > n2[4]);
}


vector<vector <float>> NMS(vector<vector <float>> lists, float thre) 
{
    // lists[0:4]: x1, x2, y1, y2; lists[4]: score
    vector<vector <float>> results;

    while(lists.size() > 0)
    {
        std::sort(lists.begin() ,lists.end(), sort_cmp);
        results.push_back(lists[0]);
        for(int i =0; i < lists.size()-1; i++)
        {
            float iou_value =iou(lists[0][0], lists[0][1], lists[0][2], lists[0][3],
                lists[i+1][0], lists[i+1][1], lists[i+1][2], lists[i+1][3]);
            if (iou_value > thre)
            {
                lists.erase(lists[i+1]);
            }
        }
        lists.erase(vec_boxs[0]);
    }
    return results;
}

