
#include<vector> 
#include<math.h>

// 生成多尺度、多宽高比的anchors。
// scale : size in pixels 
// ratio : width / hight 

std::vector<std::vector <float>> generate_anchor(float base_size, std::vector<float> ratio, std::vector<float> scale)
{
    std::vector<std::vector <float>> anchors; 
    std::vector<float> base_anchor = {0, 0, base_size - 1, base_size - 1}; 
    float horizontal_center = 0.5 * (base_size - 1);
    float vertical_center = 0.5 * (base_size - 1); 
    float width = base_size; 
    float hight = base_size; 
    float size = width * hight;  
    std::vector<float> size_ratio; 
    for(int i = 0; i < ratio.size(); i++) {
        size_ratio.push_back(base_size / ratio.at(i));
    }
    std::vector<float> wtdth_new;
    for(int j = 0; j < scale.size(); j++) {
        for(int i = 0; i < ratio.size(); i++) {
            wtdth_new.push_back( round(sqrt(size_ratio.at(i)) / sqrt(ratio.at(i)) * scale.at(j)) );
        }  
    }
    std::vector<float> hight_new;
    for(int j = 0; j < scale.size(); j++) {
        for(int i = 0; i < ratio.size(); i++) {
            hight_new.push_back( round(sqrt(size_ratio.at(i)) * sqrt(ratio.at(i)) * scale.at(j)) );
        }     
    }
    for (int i = 0; i < scale.size() * ratio.size(); i++)
    {
        std::vector<float> anchor;
        anchor.push_back(horizontal_center - 0.5 * wtdth_new.at(i)); 
        anchor.push_back(vertical_center - 0.5 * hight_new.at(i));  
        anchor.push_back(horizontal_center + 0.5 * wtdth_new.at(i)); 
        anchor.push_back(vertical_center + 0.5 * hight_new.at(i));   
        anchors.push_back(anchor); 
    }
}

std::vector<std::vector<std::vector <float>>> shift_anchor(std::vector<std::vector <float>> anchors, int feat_width, int feat_hight, int feat_stride) {

    std::vector<std::vector<std::vector <float>>> anchor_shift;
    for (size_t w = 0; w < feat_width; w++)
    {
        for (size_t h = 0; h < feat_hight; h++)
        {
            std::vector<std::vector <float>> anchors_shift_2_;
            for (size_t a = 0; a < count; a++)
            {
                std::vector <float> anchor_shift_1_;
                anchor_shift_1_.push_back(anchors[a][0] + w * feat_stride); 
                anchor_shift_1_.push_back(anchors[a][1] + h * feat_stride); 
                anchor_shift_1_.push_back(anchors[a][2] + w * feat_stride); 
                anchor_shift_1_.push_back(anchors[a][3] + h * feat_stride);  
                anchors_shift_2_.push_back(anchor_shift_1_); 
            }
            anchor_shift.push_back(anchors_shift_2_);    
        }
    }
}

int main() {
    float base_size = 16;
    std::vector<float> ratio = {0.5, 1, 2}; 
    std::vector<float> scale = {8, 16, 32}; 
    std::vector<std::vector <float>> anchors = generate_anchor(16,  ratio, scale); 
    std::vector<std::vector<std::vector <float>>> anchors_shift = shift_anchor(anchors, 5, 5, 2); 
    return 0;
}





