# Project name : MiniArcade

# MiniArcade
`
MiniArcade เป็นเกมที่รวมเกมฮิตไว้มากกว่า 5 เกม เล่นง่าย ๆ และจะพาทุกคนย้อนวัย ไปเป็นเด็กกันอีกครั้งนึง สามารถเล่นได้บน terminal ได้เลย
เกมสุดฮิตที่มีใน MiniArcade ของเราได้รับแรงบันดาลใจจากเกมยอดฮิตตลอดกาล 5 เกมต่างๆ
`

## คำอธิบาย

>โปรแกรมนี้เป็นส่วนหนึ่งของวิชา Physical Programming
>เกมที่มาเป็นแรงบันดาลใจในการสร้าง MiniArcadeของเรา
>
>1 connect four เป็นเกมกระดานที่ผู้เล่นสองคน เป็นคนละสีผลัดกันวางแผ่นสีลงในคารางแขวนแนวตั้ง 7 คอลัมน์ 
>ใครได้ครบ 4 แถวไม่ว่าจะแนวนอน หรือ แนวตั้ง หรือ แนวทะแยง ก็จะเป็นผู้ชนะ
>
>2 Bingo แน่นอนว่า เกมยอดฮิตอย่างบิงโก เกมที่จะต้องทำสัญญาลักษณ์ของเราให้เรียงติดกัน 3 แถว ใครได้ครบ 3 ก็จะเป็นผู้ชนะของเกมเกมนี้ไปเลย
>
>3 Pingpong เกมที่เราจะเป็นเปรียบเหมือนสเก็ตบอร์ด ต้องเด้งลูกบอลที่ฝั่งตรงข้ามเด้งมา ไม่ให้เข้ามาในอนาเขตของเรา 
>โดยเกมของเรา ใครเล่นได้ 5 คะแนนก่อนก็จะเป็น ผู้ชนะ
>
>4 Fruit ninja เป็นเกมยอดฮิตบนแท็บเล็ต และ สมาร์ทโฟนสมัยก่อน ที่จะใช้นิ้วขีดผลไม้เพื่อที่จะหั่นผลไม้ >โดยเกมของเราก็ทำการจำลองแนวคิดมาจากเกมยอดฮิตเกมนี้ แต่การหั่นผลไม้ของเราจะใช้คีย์บอร์ดแทนนิ้วมือ
>
>5 Snake หรือที่เรารู้จักกันดีในวัยเด็กของเราที่จะมีติดโทรศัพท์มือถือยอดฮิตในยุค 90 อย่างโนเกีย โดยเกมจะมีงูที่จะยาวขึ้นเมื่อไปกินอาหาร และจะตายตอนชนผนัง


## จุดประสงค์

>อยากให้ผู้เล่นทุกคนรู้สุกสนุกเมื่อเข้าถึงเกมส์และเพลิดเพลินไปกับเกมทั้งห้าที่ฉันได้สร้างขึ้นนอกจากนี้ โปรเจคนี้ทำให้พัฒนาทักษะในการเขียนโปรแกรมภาษาซี

## วิธีการเล่น
>
>1. เลือกเกมที่ต้องการจะเล่นโดยใส่ตัวเลขลงไป
>   - 1: Connect Four
>   - 2: Bingo
>   - 3: Pingpong
>   - 4: Fruit Ninja
>   - 5: Snake
>
>2. ยืนยันว่าต้องการเล่นเกมนี้ โดยการพิมพ์บนคีย์บอร์ด
>   - 'Y': การตกลง
>   - 'N': การปฎิเสธและกลับไปเลือกเกมใหม่
>
>3. พอยืนยันเสร็จ ก็จะไปยังเกมที่เลือกไว้

## วิธีการเล่นแต่ละเกม
>
### Connect Four
>
>โดยเกมนี้ จะใช้ผู้เล่นจำนวน 2 คน เกมนี้จะเป็นเกมที่มี 7 คอลัมน์ในแนวนอน แล้ว มี 6 คอลลัมน์ในแนวตั้ง >ผู้เล่น 1จะเป็นคนเริ่มเลือกแถวแนวนอน '0-6' และสลับเป็น ผู้เล่น 2 จะเป็นคนเลือกแถวแนวนอน '0-  >6' และก็สลับไปเรื่อย ๆ เพื่อทำให้ผู้เล่น จนมีคนใดคนนึงเรียงแถวจนครบ 4 ก็จะชนะไปเลย
>
### Bingo
>
>โดยเกมนี้ จะใช้ผู้เล่นจำนวน 2 คน เกมนี้จะเป็นเกมที่มี 3 คอลัมน์ในแนวนอน แล้ว มี 3 คอลลัมน์ในแนวตั้ง ผู้เล่น1 จะเป็นคนเริ่มเล่นเกมก่อน โดยทำสัญลักษณ์ของตัวเอง โดยใช้เลข '1-9' แทนลงไปในตำแหน่งที่ตัวเองต้องการ ผู้เล่น2 ก็ทำเหมือนกัน ถ้ามีผู้เล่นคนใดคนนึงเรียงแถวครบ 3 ก็จะชนะ
>
### Pingpong
>
>โดยเกมนี้ จะใช้ผู้เล่นจำนวน 2 คน เป็นเกมที่เราจะเป็นเหมือนบอร์ดที่โต้กับลูกบอลที่เด้งไปเด้งมาให้เข้าไปยังข้างหลังของอีกฝั่งเพื่อเอาคะแนน ผู้เล่น 1 จะเป็นบอร์ดที่อยู่ทางซ้าย ควบคุมทิศทางโดย 'W'ขึ้น 'S'ลง ผู้เล่น 2 เป็นบอร์ดที่อยู่ทางขวา ควบคุมทิศทางโดย 'I'ขึ้น 'K'ลง
>
### Fruit Ninja
>
>โดยเกมนี้จะใช้ผู้เล่นจำนวน 1 คน โดยเกมของเราก็จะขึ้น ตัว 'F'เพื่อมาใช้แทนผลไม้ ถ้าผลไม้โผล่ขึ้นมาก็ให้กดที่ปุ่ม 'W' เพื่อที่จะหั่นผลไม้ ถ้าหั่นสำเร็จ ผลไม้ก็จะหายไป แต่ถ้าไม่สำเร็จก็จะยังแสดงผลไม้ไว้บนหน้าจอ และจะชนะก็ต่อเมื่อได้ครบ 20 แต้ม
>
### Snake
>
>โดยเกมนี้จะใช้ผู้เล่นจำนวน 1 คน โดยที่ตัว 'O' จะแทนเป็นตัวงู หรือผู้เล่น โดยบังคับผ่าน 'W'ขึ้น 'A' ซ้าย 'S'ลง 'D'ขวา และกดเรื่อย ๆ ไปหาอาหาร ที่ถูกแทนด้วย '*' พอกินอาหารก็จะได้แต้มไปเรื่อยๆ เกมก็จะสิ้นสุดก็ต่อเมื่อ งูของเราไปชนกับผนัง เกมก็จะจบ

## ประโยชน์

1. เพิ่มความสนุกและประสบการณ์การเล่นเกม
2. เสริมทักษะการแก้ปัญหาในการวิเคราะห์
3. พัฒนาทักษะการบริหารเวลา บางเกมต้องจัดการเวลาอย่างดีเพื่อให้วัตถุในเกมทำงานได้อย่างเหมาะสม

## เครื่องมือ

1. Visual Studio Code
2. Dev C/C++
3. Xcode
