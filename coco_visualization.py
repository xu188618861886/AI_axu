import json
import os 
import cv2 

with open('instances_val2017.json','r') as json_file:
    J_file = json.load(json_file) 
annotation = J_file['annotations']
category = J_file['categories'] 
annotation_choose = annotation[2]
image_id = annotation_choose['image_id']
bbox = annotation_choose['bbox']
cate_id = annotation_choose['category_id']
x, y, w, h = bbox 
image_path = os.path.join('./', str(image_id).zfill(12) + '.jpg')
image = cv2.imread(image_path)
image_regtangle = cv2.rectangle(image, (int(x), int(y)), (int(x+w), int(y+h)), (255, 255, 0), 2)
category_choose = category[cate_id - 2]
text = category_choose['name']
cv2.putText(image_regtangle, text, (int(x), int(y) + 25), cv2.FONT_HERSHEY_COMPLEX, 1.0, (255, 255, 0), 2)
cv2.imshow('image', image_regtangle)
cv2.waitKey(0)
cv2.destroyAllWindows()