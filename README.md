This Project let developers  write a layout in xml which is far simpler than HTML 

sample xml code 
```xml
<?xml version="1.0" encoding="UTF-8"?>
<root>
    <title>sample</title>
    <LinearLayout
        width="400px"
        height="match_parent"
        orientation="vertical"
        background="green"
        gravity="centre"
    >
      <Button
        id="ok_but"
        width="wrap_content"
        height="wrap_content"
        text="ok"
              />

    <LinearLayout
       width="30vh"
       height="20vh"
       orientation="horizontal"
       background="blue"
    >
        <Button
           id="del_but"
           width="wrap_content"
           height="wrap_content"
           text="ok"
             />

        <Button
            id="del_but"
            width="wrap_content"
            height="wrap_content"
            text="ok"
           />
   </LinearLayout>
</LinearLayout>
</root>
```
it will create a responsive view like below

![expected_image](https://github.com/subham008/Pelican/assets/110040566/c618919b-94be-4d60-a614-df12bcfb3ac5)
