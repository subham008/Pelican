This Project let developers  write a layout in xml which is far simpler than HTML 

sample xml code 
```<?xml version="1.0" encoding="UTF-8"?>
<root>
    <title>sample</title>
    <LinearLayout
        width="match_parent"
        height="match_parent"
        orientation="vertical"

    >
    <Button
        id="ok_but"
        width="match_parent"
        height="wrap_content"
        text="ok"
        background="red"
    >
    </Button>
    <LinearLayout
      layout_width="match_parent"
      layout_height="match_parent"
      orientation="vertical"
    >
    <Button
    id="del_but"
    layout_width="match_parent"
    layout_height="wrap_content"
    text="ok"
    background="green"
    >
    </Button>
    <Button
    id="del_but"
    layout_width="match_parent"
    layout_height="wrap_content"
    text="ok"
    background="green"
     />
   </LinearLayout>
</LinearLayout>
</root>
```
it will create a view like below

