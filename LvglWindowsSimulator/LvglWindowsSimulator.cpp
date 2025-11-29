#include <Windows.h>
#include<stdio.h>
#include <LvglWindowsIconResource.h>

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include"math.h"
#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#ifdef __cplusplus
//extern "C" {
//#endif
//
//LV_IMG_DECLARE(photo_cxXszp);  // 声明 C
//    LV_IMG_DECLARE(R_C);
//
//#ifdef __cplusplus
//}
#endif

#endif // MYFUNCTIONS_H

void demo_obj(void);
void demo_obj(void)
{
    //1.得到当前活跃的屏幕
    lv_obj_t* screen = lv_scr_act();
    //2.在当前屏幕上显示一个对象
    lv_obj_t* obj = lv_obj_create(screen);
    lv_obj_set_pos(obj, 100, 50);       //设置位置
    lv_obj_set_size(obj, 100, 150);     //设置长度和宽度
    lv_obj_set_style_bg_color(obj, lv_palette_main(LV_PALETTE_PINK), 0);   //设置背景颜色
}
void demo_style(void);
void demo_style(void)
{
    //1.得到当前活跃的屏幕
    lv_obj_t* screen = lv_scr_act();
    //2.在当前屏幕上显示一个对象
    lv_obj_t* obj = lv_obj_create(screen);
    lv_obj_align(obj, LV_ALIGN_CENTER,0,0);
    //3.通过修改样式修改对象的样式
    static lv_style_t style;
    lv_style_init(&style);

    lv_style_set_width(&style, 100);
    lv_style_set_height(&style, 200);

    //lv_style_set_x(&style, 50);
    //lv_style_set_y(&style, 50);

    lv_style_set_bg_color(&style, lv_palette_main(LV_PALETTE_CYAN));
    lv_style_set_radius(&style, 25);   //设置圆角半径

    lv_obj_add_style(obj, &style, 0);   //将样式与对象关联起来
}
void demo_label(void);
void demo_label(void)
{
    //1.获取当前活动界面
    lv_obj_t* screen = lv_scr_act();
    //2.创建文本对象
    lv_obj_t* label = lv_label_create(screen);
    //设置文本内容
    lv_label_set_text(label, "hello word");
    //设置居中对齐
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);  
    //设置字体颜色  蓝色
    lv_obj_set_style_text_color(label, lv_palette_main(LV_PALETTE_CYAN), 0);
}
void demo_label_chinese(void);
void demo_label_chinese(void)
{
    //1.获取当前活动界面
    lv_obj_t* screen = lv_scr_act();
    //2.创建文本对象
    lv_obj_t* label = lv_label_create(screen);
    //设置文本内容
    lv_label_set_text(label, "牛马打工人");
    //设置居中对齐
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    //设置字体颜色  蓝色
    lv_obj_set_style_text_color(label, lv_palette_main(LV_PALETTE_CYAN), 0);
}
void demo_button(void);
void event_handler(lv_event_t* event)
{
    //printf("click\r\n");
    int code = lv_event_get_code(event);
    lv_event_get_target(event);

    if (code == LV_EVENT_CLICKED)

    {
        printf("click\r\n");
    }
}
void demo_button(void)
{
    lv_obj_t* screen = lv_scr_act();
    //1.创建按钮对象
    lv_obj_t* button = lv_btn_create(screen);
    //2.如何给按钮添加文本
    lv_obj_t* label = lv_label_create(button);
    lv_label_set_text(label, "HELLO");
    //3.给按钮添加单击事件
    lv_obj_add_event_cb(button, event_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_center(button);
}
void my_timer(lv_timer_t* timer);
void my_timer(lv_timer_t* timer)
{
    lv_obj_t* label = (lv_obj_t*)lv_timer_get_user_data(timer);
    lv_label_set_text_fmt(label, "温度:%d,湿度:%d%%", lv_rand(25, 40), lv_rand(10, 90));
}
void lesson_3_1_1(void)
{
    lv_obj_t* label = lv_label_create(lv_screen_active());
    lv_obj_set_style_bg_opa(label, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(label, lv_color_hex(0x9fce43), 0);
    lv_label_set_text(label, "HALLO WORD");
    lv_label_set_text_fmt(label, "%s%d%s%s", "www.\n", 100, "ask\n", ".net");
    lv_obj_set_style_text_font(label, &lv_font_simsun_16_cjk, 0);
    lv_obj_set_content_width(label, 750);
    lv_label_set_long_mode(label, LV_LABEL_LONG_MODE_SCROLL_CIRCULAR);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);    //文本居中对齐
    lv_obj_set_style_text_color(label, lv_color_hex(0xf1545a), 0);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);   //居中对齐
    lv_timer_t* timer1 = lv_timer_create(my_timer, 500, label);
}
static void btn_3_2_3_event_handler(lv_event_t* e);
static void btn_3_2_3_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* btn = (lv_obj_t*)lv_event_get_target(e);

    lv_obj_t* label = lv_obj_get_child(btn, 0); 
    if (code == LV_EVENT_CLICKED)
    {
        LV_LOG_USER("btn:%s",lv_label_get_text(label));
        printf("%s\n", lv_label_get_text(label));
    }
    else if (code == LV_EVENT_VALUE_CHANGED)
        LV_LOG_USER("TOGGLED");
}
void lesson_3_2_3(void)
{
    /*lv_obj_t* btn1 = lv_button_create(lv_screen_active());
    lv_obj_t* btn2 = lv_button_create(lv_screen_active());*/
    //lv_obj_t* label = lv_label_create(btn1);

    int w,y,i,x = 0;
    lv_obj_t* cont = lv_obj_create(lv_screen_active());    //创建父级容器对象，并将所有对象放在父级对象上
    lv_obj_remove_style_all(cont);
    lv_obj_center(cont);            //设置居中位置
    lv_obj_set_size(cont,400,300);  //设置大小
    //lv_obj_update_layout(btn1);    //更新按钮坐标
    //w = lv_obj_get_width(btn1);
    //y = lv_obj_get_height(btn1);
    //lv_obj_set_pos(btn2, w,y);
    for (i = 0; i < 10; i++)          //创建九个按钮
    {
        lv_obj_t* btn = lv_button_create(cont);
        lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);
        lv_obj_set_size(btn, 90, 50);
        lv_obj_t* label = lv_label_create(btn);
        lv_label_set_text_fmt(label, "%d", 9-i);
        lv_obj_center(label);

        lv_obj_update_layout(btn);
        w = lv_obj_get_width(btn);          //获取当前位置
        y = lv_obj_get_height(btn);
        if ((i % 3) == 0)
        {
            w = 0;
            y = i / 3 * (y+10);
        }
        else
        {
            w = (w+10) * (i % 3);
            y = i / 3 * (y+10);
        }
        lv_obj_set_pos(btn, w, y);
        lv_obj_add_event_cb(btn, btn_3_2_3_event_handler, LV_EVENT_ALL,NULL);
    }
}
void lesson_3_3_1(void)
{
    lv_obj_t* slider = lv_slider_create(lv_screen_active());  //创建滑动条对象
    lv_obj_set_pos(slider,900,600);
}
static void event_handler_3_4(lv_event_t* e);
void my_timer_3(lv_timer_t* timer)   //进度条定时器
{
    /*Use the user_data*/
   /* extern lv_obj_t* btn;*/
    lv_obj_t* bar = (lv_obj_t*)lv_timer_get_user_data(timer);    //获取传入对象
    lv_obj_t* parent = lv_obj_get_parent(bar);
    lv_obj_t* btn = lv_obj_get_child(parent, 1);
    lv_obj_t* label = lv_obj_get_child(parent, 2);     //获取父对象的
    lv_obj_align_to(label,bar,LV_ALIGN_RIGHT_MID,0,0);
    static int a = 0;
    a += 10;
    lv_bar_set_value(bar, a, LV_ANIM_ON);   //更新设置当前value值
    lv_label_set_text_fmt(label, "%d", a);
    if (a == 100)
    {
        a = 0;
        lv_obj_set_style_bg_color(bar, lv_color_hex(0x3f9f4a),LV_PART_INDICATOR);    //加载完成以后变成绿色
        lv_obj_clear_state(btn, LV_STATE_DISABLED);     //清除按钮状态
        lv_timer_del(timer);    //删除定时器
    }
}
void lesson_3_3_2(void)            //进度条代码合集
{
    static lv_style_t style_bg;
    static lv_style_t style_indic;         //创建本地样式

    lv_style_init(&style_bg);              //初始化背景主题
    lv_style_set_radius(&style_bg, 15);        //设置圆角半径0
    lv_style_set_anim_duration(&style_bg, 1000);

    lv_style_init(&style_indic);
    lv_style_set_radius(&style_indic, 51);
    lv_style_set_bg_color(&style_indic, lv_color_hex(0x067fd7));    //加载完成以后变成绿色

    lv_obj_t* cont = lv_obj_create(lv_screen_active());  //创建父级容器
    lv_obj_set_size(cont,LV_PCT(100), 400);     //设置容器自适应子对象大小
    lv_obj_t* bar = lv_bar_create(cont);   //创建进度条对象 第一个子对象
    lv_obj_set_size(bar, LV_PCT(90), 40);  //设置进度条大小
    lv_obj_center(bar);                    //居中显示进度条

    lv_bar_set_value(bar, 0, LV_ANIM_ON);      //设置进度条的值，且有动画效果
    lv_obj_add_style(bar, &style_bg,LV_PART_MAIN);     //为进度条添加背景格式
    lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);   //为进度条添加触发格式

    lv_obj_t* btn = lv_btn_create(cont);         //创建按钮对象，第二个子对象
    lv_obj_t* label = lv_label_create(btn);

    lv_label_set_text(label, LV_SYMBOL_OK "Upgrade");
    lv_obj_set_size(btn, 100, 50);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 0, 0);     //设置底部对齐居中
    lv_obj_align_to(label, btn, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(btn, event_handler_3_4, LV_EVENT_CLICKED, bar);  //为按钮添加事件

    label = lv_label_create(cont);      //创建标签对象，第三个子对象
    lv_obj_align_to(label, bar, LV_ALIGN_RIGHT_MID, 0, 0);
}
static void event_handler_3_4(lv_event_t* e)      //进度条代码按键处理函数
{
    lv_obj_t* btn = (lv_obj_t*)lv_event_get_target(e);
    lv_obj_t* bar = (lv_obj_t*)lv_event_get_user_data(e);   //获取当前bar值
    lv_timer_t* timer = lv_timer_create(my_timer_3, 1000,bar);  //创建定时器，并传入bar数据
    lv_obj_set_style_bg_color(bar, lv_color_hex(0x067fd7),LV_PART_INDICATOR);    //点击以后变成蓝色
    lv_obj_add_state(btn, LV_STATE_DISABLED);    //点动后禁用按钮
}
static void event_slider(lv_event_t* e);          //滑动条事件处理函数
void lesson_3_4_4(void)   //滑动条示例代码
{
    lv_obj_t* cont = lv_obj_create(lv_screen_active());     //创建父对象
    lv_obj_t* slider = lv_slider_create(cont);
    lv_obj_add_flag(slider, LV_OBJ_FLAG_ADV_HITTEST);       //设置滑动条只能拖动按钮改变值
    lv_obj_remove_style_all(cont);
    lv_obj_center(cont);
    //lv_obj_set_size(cont, LV_SIZE_CONTENT, LV_SIZE_CONTENT);  //根据子对象自动设置大小
    lv_obj_set_size(slider, 100, 500);      //设置滑动条大小
    lv_obj_set_size(cont, LV_SIZE_CONTENT, LV_SIZE_CONTENT);  //根据子对象自动设置大小
    //lv_obj_center(cont);
    //lv_obj_set_style_opa(cont, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_center(slider);                 //居中滑动条
    lv_obj_set_style_radius(slider, 20, LV_PART_MAIN);          //设置滑动条背景圆角
    lv_obj_set_style_radius(slider, 20, LV_PART_INDICATOR);    //设置显示部分圆角
    //lv_obj_set_style_opa(slider,LV_OPA_TRANSP , LV_PART_KNOB);  //设置按钮透明度LV_OPA_COVER
    lv_obj_set_style_radius(slider, 0, LV_PART_KNOB);     //设置滑动条按钮圆角为0
    lv_obj_set_style_pad_top(slider, -50, LV_PART_KNOB);   //-51
    lv_obj_set_style_pad_left(slider, -1, LV_PART_KNOB);
    lv_obj_set_style_pad_right(slider, -1, LV_PART_KNOB);
    lv_obj_set_style_pad_bottom(slider, -39, LV_PART_KNOB);  //-40

    lv_obj_set_style_bg_color(slider, lv_color_hex(0xffffff), LV_PART_KNOB);   //设置滑动条按钮颜色白色
    lv_obj_set_style_bg_color(slider, lv_color_hex(0x5a5041), LV_PART_MAIN);   //设置滑动条背景颜色灰色
    lv_obj_set_style_bg_color(slider, lv_color_hex(0xffffff),LV_PART_INDICATOR);   //设置滑动条显示部分颜色白色
    //lv_obj_set_style_bg_color(slider, lv_color_hex(0xffff4d), LV_PART_INDICATOR);   //设置滑动条显示部分颜色白色
    lv_obj_set_style_transform_width(slider, 0, LV_PART_KNOB | LV_STATE_PRESSED);  //设置按下滑动条按钮后，按钮尺寸不改变
    lv_obj_set_style_transform_height(slider, 0, LV_PART_KNOB | LV_STATE_PRESSED);

    lv_obj_t* label = lv_label_create(cont);     //创建标签对象
    lv_obj_set_style_text_font(label,&lv_font_montserrat_40,0);   //设置标签字体大小40
    lv_label_set_text(label, LV_SYMBOL_EYE_OPEN);
    lv_obj_set_style_bg_color(label, lv_color_hex(0xd3d3d3), 0);   //设置标签背景颜色
    //lv_label_set_text(label, "#d3d3d3 abcd#");
    lv_obj_align(label,LV_ALIGN_CENTER,0,200);        //底部居中对齐
    lv_obj_add_event_cb(slider, event_slider, LV_EVENT_VALUE_CHANGED,NULL);  //关联值改变事件
    //lv_obj_add_event_cb(slider, event_slider, LV_EVENT_HIT_TEST, NULL);   //点击无效，无论在哪滑动都有效
}
static void event_slider(lv_event_t* e)          //滑动条事件处理函数
{
    lv_obj_t* slider=(lv_obj_t*)lv_event_get_target(e);  //获取触发事件的滑动条对象
    static int slider_value;
    slider_value = lv_slider_get_value(slider);    //获取当前滑动条的值
    printf("%d\n", slider_value);
    if ((slider_value > 98) || (slider_value < 4))   //判断是否达到透明范围
        lv_obj_set_style_opa(slider, LV_OPA_TRANSP, LV_PART_KNOB);
    else
        lv_obj_set_style_opa(slider, LV_OPA_COVER, LV_PART_KNOB);
}
void my_timer4(lv_timer_t* timer)
{
    lv_obj_t* arc = (lv_obj_t*)lv_timer_get_user_data(timer);  //创建圆弧对象
    lv_obj_t* parent = lv_obj_get_parent(arc);
    lv_obj_t* label = lv_obj_get_child(parent, 2);     //获取父对象第三个子对象（label1）
    static int arc_value = 0;
    arc_value += 1;
    if (arc_value > 100)
        arc_value = 0;
    //static int arc_value = lv_arc_get_value(arc);
    lv_arc_set_value(arc, arc_value);               //更新当前圆弧值
    lv_label_set_text_fmt(label, "%d°", arc_value);         //改变当前温度值
}
void lesson_3_5_2(void)   //圆弧控件示例代码
{
    lv_obj_t* cont = lv_obj_create(lv_screen_active());   //创建父级对象
    lv_obj_t* arc = lv_arc_create(cont);
    lv_obj_t* label = lv_label_create(cont);
    lv_obj_t* label1 = lv_label_create(cont);

    lv_obj_set_size(arc,200,200);          //设置圆弧对象大小
    lv_obj_set_size(cont, LV_SIZE_CONTENT, LV_SIZE_CONTENT);  //根据子对象自动调整父对象大小
    lv_obj_center(cont);     //父对象居中
    lv_arc_set_value(arc, 100);          //设置圆弧的值
    lv_obj_center(arc);        //居中对齐
    lv_obj_set_style_arc_width(arc, 20,LV_PART_MAIN);    //调节背景圆弧宽度
    lv_obj_set_style_arc_width(arc, 20, LV_PART_INDICATOR);    //调节前景圆弧宽度
    //lv_obj_set_style_pad_all(arc, 40,LV_PART_INDICATOR);
    //lv_obj_set_style_pad_all(arc, 0, LV_PART_KNOB);
    lv_obj_set_style_arc_rounded(arc, 0, LV_PART_INDICATOR);   //设置成方角
    lv_obj_set_style_arc_rounded(arc, 0, LV_PART_MAIN);       //设置成方的角度
    lv_obj_remove_style(arc,NULL, LV_PART_KNOB);       //去掉旋钮样式

    lv_label_set_text(label, "RooM");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 90);     //设置文本居中对齐
    lv_obj_set_style_text_font(label, &lv_font_montserrat_32, LV_PART_MAIN);

    lv_label_set_text_fmt(label1, "%d°",0);         //设置当前温度值
    lv_obj_align(label1, LV_ALIGN_CENTER, 0, 0);     //设置文本居中对齐
    lv_obj_set_style_text_font(label1, &lv_font_montserrat_32, LV_PART_MAIN);
    lv_obj_add_state(arc, LV_STATE_DISABLED);    //点动后禁用圆弧
    lv_timer_create(my_timer4, 200, arc);
}
//环形加载器示例代码
void lesson_3_6_1(void)
{
    lv_obj_t* cont = lv_spinner_create(lv_screen_active());    //创建父级对象
    lv_obj_t* spinner = lv_spinner_create(cont);       //创建环形加载器
    lv_obj_remove_style_all(cont);
    lv_obj_set_size(spinner, 200, 200);           //设置环形加载器大小
    lv_obj_set_size(cont, LV_SIZE_CONTENT, LV_SIZE_CONTENT);     //父对象大小自适应调整
    lv_obj_center(cont);                   //父对象居中对齐
    lv_obj_center(spinner);
    lv_spinner_set_anim_params(spinner, 1000, 90);    //设置动画时间及转圈角度
    lv_obj_set_style_arc_rounded(spinner, 0, LV_PART_INDICATOR);  //取消显示部分圆角
    //lv_obj_set_style_arc_opa(spinner, LV_OPA_TRANSP, LV_PART_MAIN);   //透明化
    lv_obj_set_style_arc_color(spinner, lv_palette_main(LV_PALETTE_GREEN), LV_PART_INDICATOR);  //指示部分变为绿色
    //lv_obj_set_style_arc_width(spinner, 20, LV_PART_INDICATOR);   //调整宽度
    //lv_obj_set_style_pad_all(spinner, 14, LV_PART_INDICATOR);
    lv_obj_set_style_pad_all(spinner, -10, LV_PART_INDICATOR);
    lv_obj_set_style_pad_all(spinner, 50, LV_PART_MAIN);
}
//按钮控件事件函数
void btnm_event(lv_event_t* e)                       //矩阵按钮事件函数（计算器）
{
    lv_obj_t* button = (lv_obj_t*)lv_event_get_target(e);    //获取按下的对象
    int btnm_id = lv_buttonmatrix_get_selected_button(button);   //获取触发的按钮
    static int datas[20] = { 0 };         //输入数字存储数组
    static int count = 0;            //输入数字计数
    static int data_count = 0;       //输入整数计数
    static float datas_count[20] = { 0 };    //输入数据数组
    static float result = 0;                  //输出结果
    static int notion_count = 0;         //符号计数变量
    static int notion[20] = { 0 };
    static float array_datas[20] = { 0 };
    static int array_notion[20] = {0};
    int i = 0;
    //printf("id:%d\n", btnm_id);    //打印当前触发的按钮id
    switch (btnm_id)          //判断id号
    {
        //功能按键
    case 0:{
        count = 0;
        data_count = 0;
        notion_count = 0;
    } break;     //AC功能
    case 2:if(count>0)count -= 1; break;                    //delete功能
    case 19: {                                  //输出结果功能
        int j = 0;
        for (i = 0; i < count; i++)
            datas_count[data_count] += pow(10, i) * datas[count - 1 - i];   //计算每一项的值，并存储
        printf("now_datas=%f\n", datas_count[data_count]);       //输出最后一个输入的值
        count = 0;
        for (i = 0; i < notion_count; i++)
            if ((notion[i] == 2) || (notion[i] == 3))          //遍历判断乘除符号
            {
                    array_datas[j] = datas_count[i];             //提取乘除项
                    array_datas[j + 1] = datas_count[i + 1];
                if (notion[i] == 2)
                {
                    array_notion[j] = 2;
                    printf("notion:\\\n");
                }
                else
                {
                    array_notion[j] = 3;
                    printf("notion:*\n");
                }
                if ((notion[i + 1] == 2) || (notion[i + 1] == 3))    //判断邻位是否为*\号
                    j++;
                else
                    j += 2;
            }
        for (i = 0; i < notion_count; i++)
            if ((notion[i] == 4) || (notion[i] == 5))          //遍历判断加减符号
            {
                if ((notion[i + 1] == 4) || (notion[i + 1] == 5)||(notion[i+1]==0))   //判断相邻是否同号，同号则提取两项,最后为等号也同理
                {
                    array_datas[j] = datas_count[i];             //提取加减项
                    array_datas[j + 1] = datas_count[i + 1];
                }
                else
                {
                    array_datas[j] = datas_count[i];          //相邻有乘除项则提取一项
                }
                if (notion[i] == 4)
                    array_notion[j] = 4;
                else
                    array_notion[j] = 5;
                j++;
            }
        for (i = 0; i < j; i++)
        {
            switch (array_notion[i])
            {
            case 3: {                         //判断是否为乘法
                if (i == 0)
                    result = array_datas[i] * array_datas[i + 1];
                else
                    result = result * array_datas[i + 1];
            }; break;
            case 2: {
                if (i == 0)
                    result = (float)array_datas[i] / (float)array_datas[i + 1];
                else
                    result = (float)result / array_datas[i + 1];
            }; break;
            case 4: {
                if (i == 0)
                    result = array_datas[i] - array_datas[i + 1];
                else
                    result -= array_datas[i + 1];
            }break;
            case 5: {
                if (i == 0)
                    result = array_datas[i] + array_datas[i + 1];
                else
                    result += array_datas[i + 1];
            }break;
            }
        }
        printf("result=%f\n", result);         //打印输出结果
        for (i = 0; i < data_count; i++)       //清除数据缓冲区域
            datas_count[i] = 0;
        for (i = 0; i < notion_count; i++)     //清除符号缓存区域
            notion[i] = 0;
        j = 0;            //清零
        count = 0;         //清楚数据计数标志
        data_count = 0;     //清除计算数据标志
        notion_count = 0;    //清除符号计数标志
        result = 0;              //清除结果
    }; break;
    case 4: datas[count] = 7;count++; break;                        //7
    case 5: datas[count] = 8;count++; break;                        //8
    case 6:datas[count] = 9; count++; break;                        //9
    case 8:datas[count] = 4; count++; break;                        //4
    case 9:datas[count] = 5; count++; break;                        //5
    case 10:datas[count] = 6; count++; break;                       //6
    case 12:datas[count] = 1; count++; break;                       //1
    case 13:datas[count] = 2; count++; break;                       //2
    case 14:datas[count] = 3; count++; break;                       //3
    case 16:datas[count] = 0; datas[count+1] = 0; count+=2; break;  //00
    case 17:datas[count] = 0; count++; break;                       //0
    default: {                            //算数功能
        for (i = 0; i < count; i++)           
            datas_count[data_count] += pow(10, i)  * datas[count - 1 - i];   //计算每一项的值，并存储
        printf("now_datas=%f\n", datas_count[data_count]);       //输出每一个输入的值
        data_count++;
        count = 0;
        switch (btnm_id)
        {
            case 1:notion[notion_count] = 1; notion_count++; break;      //记录%符号
            case 3:notion[notion_count] = 2; notion_count++; break;      //记录\符号
            case 7:notion[notion_count] = 3; notion_count++; break;      //记录*符号
            case 11:notion[notion_count] = 4; notion_count++; break;      //记录-符号
            case 15:notion[notion_count] = 5; notion_count++; break;      //记录+符号
        }
        }
    }
}
//矩阵按钮控件
void lesson_3_7_1(void)
{
    lv_obj_t* btnm = lv_buttonmatrix_create(lv_screen_active());    //创建矩阵按键对象
    static const char* my_map[] = { "AC","%","delete","/","\n",
                                    "7","8","9","*","\n",
                                    "4","5","6","-","\n",
                                    "1","2","3","+","\n",
                                    "00","0",".","=",""};  //设定矩阵键盘各个按钮的名称及格式
    printf("niuma%s", my_map[0]);
    lv_obj_center(btnm);     //居中对齐
    lv_obj_set_size(btnm, 600, 400);    //设置矩阵按键大小
    lv_buttonmatrix_set_map(btnm, my_map);  //设置每个按键的名称

    lv_buttonmatrix_set_button_ctrl_all(btnm,LV_BUTTONMATRIX_CTRL_CHECKED);    //设置每个按钮(状态切换)
    lv_obj_set_style_text_font(btnm, &lv_font_montserrat_34, LV_PART_ITEMS);     //设置按钮字体格式
    lv_obj_add_event_cb(btnm, btnm_event, LV_EVENT_VALUE_CHANGED,NULL);
}
//列表刷新事件函数
void refresh_handler(lv_event_t* e)
{
    lv_obj_t* list = (lv_obj_t*)lv_event_get_user_data(e);
    lv_obj_t* btn;
    lv_obj_clean(list);                  //清除所有子对象
    lv_list_add_text(list, "Select Wife");
    //btn = lv_list_add_button(list, LV_SYMBOL_WIFI, "Wi-Fi1");          //创建按钮对象
    //lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_GREEN), LV_PART_MAIN);
    printf("enter\n");
}
//列表控件
void lesson_3_8_1(void)
{
    lv_obj_t* cont = lv_obj_create(lv_screen_active());      //创建父对象
    lv_obj_remove_style_all(cont);
    lv_obj_center(cont);                //居中对齐

    lv_obj_t* list1 = lv_list_create(cont);          //创建列表对象1
    lv_obj_t* list2 = lv_list_create(cont);          //创建列表对象2
    lv_obj_t* btn1 = lv_button_create(cont);           //创建刷新按钮对象
    lv_obj_t* btn;
    lv_obj_t* label = lv_label_create(btn1);          //创建标签对象

    lv_label_set_text(label, LV_SYMBOL_REFRESH"Refesh");           //设置名称
    lv_obj_set_style_bg_color(btn1,lv_color_hex(0x00ff00), LV_PART_MAIN);   //设定按钮的背景色
    lv_list_add_text(list1, "connected list");
    btn = lv_list_add_button(list1, LV_SYMBOL_WIFI, "Wi-Fi1");          //创建按钮对象
    //lv_obj_set_style_bg_color(list1, lv_palette_main(LV_PALETTE_GREEN), LV_PART_MAIN);
    lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_GREEN), LV_PART_MAIN);
    lv_obj_set_size(list1, 400, LV_SIZE_CONTENT);
    lv_obj_set_size(list2, 400, 200);
    lv_obj_set_size(cont, LV_PCT(90), LV_PCT(90));
    lv_obj_set_style_radius(list1, 0, LV_PART_MAIN);   //清除列表圆角 
    lv_obj_set_style_radius(list2, 0, LV_PART_MAIN);

    lv_obj_align_to(btn1, cont, LV_ALIGN_TOP_MID, 0, 0);     //按钮顶部居中对齐
    lv_obj_align_to(list1, btn1, LV_ALIGN_OUT_BOTTOM_MID,0,0);
    lv_obj_align_to(list2, list1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);

    //lv_list_add_text(list1, "connected list");
    //btn = lv_list_add_button(list1, LV_SYMBOL_WIFI, "Wi-Fi1");          //创建按钮对象
    //lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_BLUE_GREY), 0);
    lv_list_add_text(list2, "Select Wife");
    lv_obj_t* list_btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi1.akjlhdakdhlakdlkjadhlahdlahdlashdlakdhlaaldkhaldadad");          //创建按钮对象
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi2");          //创建按钮对象
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi3");          //创建按钮对象
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi4");          //创建按钮对象
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi5");          //创建按钮对象
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi6");          //创建按钮对象
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi7");          //创建按钮对象
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi8");          //创建按钮对象
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi9");          //创建按钮对象
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi10");         //创建按钮对象
    lv_obj_add_event_cb(btn1, refresh_handler,LV_EVENT_CLICKED , list2);
    label = lv_obj_get_child(list_btn, 1);
    lv_obj_set_style_anim_duration(label, 20000, 0);             //调整文字滚动速度
}
//开关控件
void lesson_3_9_1(void)
{
    lv_obj_t* sw = lv_switch_create(lv_screen_active());     //创建开关控件
    lv_obj_set_size(sw, 240, 100);       //设置开关大小
    lv_obj_center(sw);                   //居中对齐
    lv_obj_set_style_pad_all(sw, 25, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(sw, LV_OPA_TRANSP, LV_PART_MAIN);   //背景透明化
    lv_obj_set_style_bg_opa(sw, LV_OPA_100, LV_PART_INDICATOR);   //显示完全不透明
    lv_obj_set_style_bg_color(sw, lv_color_hex(0x909090), LV_PART_INDICATOR);   //设置显示背景颜色
    lv_obj_set_style_bg_color(sw, lv_color_hex(0x7FFFAA), LV_PART_KNOB|LV_STATE_CHECKED);   //设置显示背景颜色
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0x909090), LV_PART_KNOB);   //设置显示背景颜色
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0xffffff), LV_PART_MAIN);   //设置颜色
    lv_obj_set_style_pad_all(sw, -10, LV_PART_KNOB);
    lv_obj_set_style_pad_all(sw, 10, LV_PART_KNOB|LV_STATE_CHECKED);

}
//复选框控件
void lesson_3_10_1(void)
{
    lv_obj_t* cb = lv_checkbox_create(lv_screen_active());    //创建复选框对象
    lv_obj_t* list = lv_list_create(lv_screen_active());      //创建列表对象
    lv_obj_set_size(cb, 200, 100);
    lv_obj_set_size(list, 200, 300);
    lv_obj_center(list);
    lv_obj_t* btn;
    int i;
    for (i = 0; i < 9; i++)
    {
         btn = lv_list_add_button(list, NULL, "");
         cb = lv_checkbox_create(btn);    //创建复选框对象
         //lv_obj_set_size(btn, 100, 100);
         //lv_obj_align_to(cb, btn, LV_ALIGN_LEFT_MID,0,0);        //居中对齐
         lv_checkbox_set_text(cb, "yestday");
         lv_obj_set_style_text_font(cb, &lv_font_montserrat_34, LV_PART_MAIN);
         lv_obj_set_size(btn, LV_SIZE_CONTENT, LV_SIZE_CONTENT);   //根据子对象自动调整大小
         //lv_obj_set_style_opa(cb, LV_OPA_TRANSP, LV_PART_INDICATOR);
         lv_obj_set_style_bg_color(cb, lv_color_hex(0xff00ff), LV_PART_INDICATOR);
         //lv_obj_set_style_opa(cb, LV_OPA_0, LV_PART_INDICATOR);
         //lv_obj_set_style_bg_color(cb, lv_color_hex(0xff00ff), LV_PART_INDICATOR);
         lv_obj_align_to(cb, btn, LV_ALIGN_LEFT_MID, 0, 0);        //居中对齐
    }
    lv_obj_set_size(list, LV_SIZE_CONTENT,300);
}
//线条控件
void lesson_3_11_1(void)
{
    static lv_point_precise_t line_points[] = { {5,10}, {70, 70}, {120, 10}, {180, 60}, {240, 10} };

    /*Create style*/
    static lv_style_t style_line;
    lv_style_init(&style_line);         //初始化线条对象样式
    lv_style_set_line_width(&style_line, 12);        //设置线条宽度
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_line_rounded(&style_line, true);

    /*Create a line and apply the new style*/
    lv_obj_t* line1;
    line1 = lv_line_create(lv_screen_active());    //创建线条对象
    lv_line_set_points(line1, line_points, 5);     /*Set the points*/
    lv_obj_add_style(line1, &style_line, 0);
    lv_obj_center(line1);
}
//按钮开关灯事件函数
void led_button_event(lv_event_t* e)
{
    lv_obj_t* led = (lv_obj_t*)lv_event_get_user_data(e);
    lv_led_toggle(led);     //翻转led灯状态
}
//LED灯控件
void lesson_3_12_1(void)
{
    lv_obj_t* led = lv_led_create(lv_screen_active());   //创建led对象
    lv_obj_t* slider = lv_slider_create(lv_screen_active());     //创建滑动条对象
    lv_obj_center(led);             //居中对象
    lv_led_set_color(led,lv_color_hex(0x28ff28));
    //lv_led_toggle(led);
    lv_obj_t* button = lv_button_create(lv_screen_active());
    lv_obj_set_size(button, 100, 50);     //设置按钮大小
    lv_obj_set_size(led, 100, 50);      //设置led大小
    lv_led_set_color(led, lv_color_hex(0xff00ff));   //设置led颜色红色
    lv_obj_set_size(slider, 50, 300);   //设置滑动条大小
    lv_obj_align_to(button, led, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);   //按钮与led对齐
    lv_obj_align_to(slider, button, LV_ALIGN_OUT_RIGHT_TOP, 0, 50);   //滑动条与按钮对齐
    lv_obj_set_style_pad_all(slider, -120, LV_PART_INDICATOR);
    lv_obj_set_style_pad_all(slider, -5, LV_PART_KNOB);
    lv_obj_set_style_pad_left(slider, -5, LV_PART_KNOB);
    lv_obj_set_style_radius(slider, 0, LV_PART_KNOB);
    lv_obj_set_style_opa(slider, LV_OPA_50, LV_PART_MAIN);     //背景透明化
    //lv_obj_set_size(button, 200, 100);
    lv_obj_add_event_cb(button, led_button_event, LV_EVENT_CLICKED, led);   //关联事件函数
}
void button_event_3_13_2(lv_event_t* e);
//滚轮控件
static lv_obj_t* roller1;    //定义三个滚轮指针
static lv_obj_t* roller2;
static lv_obj_t* roller3;

//char hour[32] = { 0 };   //时、分、秒变量
//char min[32] = { 0 };
//char sec[32] = { 0 };
void lessom_3_13_1(void)
{
#if 0
    lv_obj_t* roller1 = lv_roller_create(lv_screen_active());
    lv_obj_set_style_text_line_space(roller1, 20, LV_PART_MAIN);     //调整滚轮每一个之间的间距
    lv_obj_set_style_anim_duration(roller1,500,LV_PART_MAIN);      //调整滚动持续时间
    lv_roller_set_options(roller1,
        "January\n"
        "February\n"
        "March\n"
        "April\n"
        "May\n"
        "June\n"
        "July\n"
        "August\n"
        "September\n"
        "October\n"
        "November\n"
        "December",
        LV_ROLLER_MODE_INFINITE);

    lv_roller_set_visible_row_count(roller1, 4);
    lv_obj_center(roller1);
    //lv_obj_set_style_text_line_space(roller1,100,LV_PART_MAIN);
    lv_obj_add_event_cb(roller1, event_handler, LV_EVENT_ALL, NULL);
#elif 0
    /*A style to make the selected option larger*/
    static lv_style_t style_sel;
    lv_style_init(&style_sel);
    lv_style_set_text_font(&style_sel, &lv_font_montserrat_22);
    lv_style_set_bg_color(&style_sel, lv_color_hex3(0xf88));
    lv_style_set_border_width(&style_sel, 2);
    lv_style_set_border_color(&style_sel, lv_color_hex3(0xf00));

    const char* opts = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10";
    lv_obj_t* roller;

    /*A roller on the left with left aligned text, and custom width*/
    roller = lv_roller_create(lv_screen_active());
    lv_roller_set_options(roller, opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller, 2);
    lv_obj_set_width(roller, 100);
    lv_obj_add_style(roller, &style_sel, LV_PART_SELECTED);
    lv_obj_set_style_text_align(roller, LV_TEXT_ALIGN_LEFT, 0);
    lv_obj_set_style_bg_color(roller, lv_color_hex3(0x0f0), 0);
    lv_obj_set_style_bg_grad_color(roller, lv_color_hex3(0xafa), 0);
    lv_obj_set_style_bg_grad_dir(roller, LV_GRAD_DIR_VER, 0);
    lv_obj_align(roller, LV_ALIGN_LEFT_MID, 10, 0);
    lv_obj_add_event_cb(roller, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(roller, 2, LV_ANIM_OFF);

    /*A roller on the middle with center aligned text, and auto (default) width*/
    roller = lv_roller_create(lv_screen_active());
    lv_roller_set_options(roller, opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller, 3);
    lv_obj_add_style(roller, &style_sel, LV_PART_SELECTED);
    lv_obj_align(roller, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(roller, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(roller, 5, LV_ANIM_OFF);

    /*A roller on the right with right aligned text, and custom width*/
    roller = lv_roller_create(lv_screen_active());
    lv_roller_set_options(roller, opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller, 4);
    lv_obj_set_width(roller, 80);
    lv_obj_add_style(roller, &style_sel, LV_PART_SELECTED);
    lv_obj_set_style_text_align(roller, LV_TEXT_ALIGN_RIGHT, 0);
    lv_obj_align(roller, LV_ALIGN_RIGHT_MID, -10, 0);
    lv_obj_add_event_cb(roller, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(roller, 8, LV_ANIM_OFF);
#elif 0
    roller1 = lv_roller_create(lv_screen_active());
    roller2 = lv_roller_create(lv_screen_active());
    roller3 = lv_roller_create(lv_screen_active());
    lv_obj_set_size(roller1, 80, 300);   //设置滚轮1大小
    lv_obj_set_size(roller2, 80, 300);   //设置滚轮2大小
    lv_obj_set_size(roller3, 80, 300);   //设置滚轮3大小

    lv_obj_set_style_text_line_space(roller1, 10, LV_PART_MAIN);     //调整滚轮每一个之间的间距
    lv_obj_set_style_text_line_space(roller2, 10, LV_PART_MAIN);     //调整滚轮每一个之间的间距
    lv_obj_set_style_text_line_space(roller3, 10, LV_PART_MAIN);     //调整滚轮每一个之间的间距
    lv_obj_set_style_anim_duration(roller1, 100, LV_PART_MAIN);      //调整滚动持续时间

    lv_roller_set_options(roller1,               //时针滚轮
        "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12",
        LV_ROLLER_MODE_INFINITE);

    lv_roller_set_options(roller2,               //分针滚轮
        "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n"
        "11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n"
        "21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n"
        "31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n"
        "41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n"
        "51\n52\n53\n54\n55\n56\n57\n58\n59\n60",
        LV_ROLLER_MODE_INFINITE);

    lv_roller_set_options(roller3,               //秒针滚轮
        "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n"
        "11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n"
        "21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n"
        "31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n"
        "41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n"
        "51\n52\n53\n54\n55\n56\n57\n58\n59\n60",
        LV_ROLLER_MODE_INFINITE);

    lv_roller_set_visible_row_count(roller1, 4);     //设置滚轮可见行数
    lv_roller_set_visible_row_count( roller2, 4);
    lv_roller_set_visible_row_count(roller3, 4);
    lv_obj_center(roller2);      //分针滚轮居中对齐

    //char hour[32] = {0};   //时、分、秒变量
    //char min[32] = {0};
    //char sec[32] = {0};
    //lv_roller_get_selected_str(roller1, hour, sizeof(hour));      //获取当前选中时、分、秒
    //lv_roller_get_selected_str(roller2, min, sizeof(min));
    //lv_roller_get_selected_str(roller3, sec, sizeof(sec));

    //printf("hour=%s\nmin=%s\nsec=%s\n", hour, min, sec);
    lv_obj_align(roller1, LV_ALIGN_CENTER, -150, 0);   //时针滚轮左对齐
    lv_obj_align(roller3, LV_ALIGN_CENTER, 150, 0);    //秒针滚轮右对齐
    //lv_obj_set_style_text_line_space(roller1,100,LV_PART_MAIN);
    lv_obj_add_event_cb(roller1, event_handler, LV_EVENT_ALL, NULL);   //关联事件函数

    lv_obj_t* button = lv_button_create(lv_screen_active());   //创建按钮对象
    lv_obj_align_to(button, roller2, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);   //按钮与分针滚轮对齐
    lv_obj_set_size(button, 100, 50);     //设置按钮大小
    lv_obj_add_event_cb(button, button_event_3_13_2, LV_EVENT_CLICKED, NULL);     //添加按钮点击事件函数
#endif
}
void button_event_3_13_2(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    printf("Button is clicked\n");
    char hour[32] = { 0 };   //时、分、秒变量
    char min[32] = { 0 };
    char sec[32] = { 0 };
    lv_roller_get_selected_str(roller1, hour, sizeof(hour));      //获取当前选中时、分、秒
    lv_roller_get_selected_str(roller2, min, sizeof(min));
    lv_roller_get_selected_str(roller3, sec, sizeof(sec));

    printf("%s:%s:%s\n", hour, min, sec);
}
//微调框控件关联事件函数
static lv_obj_t* spinbox;
#define total_digit 5          //定义总位数
#define decimal_digit 2        //定义小数位数
static void lv_spinbox_increment_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT)
    {
        lv_spinbox_increment(spinbox);
        //lv_spinbox_step_next(spinbox);
        //int32_t a=lv_spinbox_get_value(spinbox);
        //int32_t b = a / pow(10, total_digit - decimal_digit);   //获取整数部分
        //int32_t c = a % (int32_t)pow(10, total_digit - decimal_digit); //获取小数部分
        //float number = (float)a / (float)pow(10, total_digit - decimal_digit);  //计算最终数值
        //printf("number=%f\n", number);
        //printf("youyi\na=%d\nb=%d\nc=%d\n",a,b,c);
    }
}

static void lv_spinbox_decrement_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT)
    {
        lv_spinbox_decrement(spinbox);
        //lv_spinbox_step_prev(spinbox);
        //int32_t a = lv_spinbox_get_value(spinbox);

        printf("zuoyi\n");
    }
}
//微调框值变化事件函数
void lv_spinbox_change_event_cb(lv_event_t* t)      
{
    int32_t a = lv_spinbox_get_value(spinbox);
    //int32_t b = a / pow(10, total_digit - decimal_digit);   //获取整数部分
    //int32_t c = a % (int32_t)pow(10, total_digit - decimal_digit); //获取小数部分
    float number = (float)a / pow(10, total_digit - decimal_digit);  //计算最终数值
    printf("number=%6.3f\n", number);
}
//微调框控件
void lesson_3_14_1(void)
{
#if 1
    spinbox = lv_spinbox_create(lv_screen_active());
    lv_spinbox_set_range(spinbox, 0, 99999);
    lv_spinbox_set_digit_format(spinbox, 5, 2);
    lv_spinbox_step_prev(spinbox);
    lv_obj_set_width(spinbox,LV_SIZE_CONTENT);      //自适应宽度
    //lv_obj_set_width(spinbox, 300);
    lv_obj_center(spinbox);   //居中对齐
    lv_obj_set_style_text_font(spinbox, &lv_font_montserrat_32, 0);   //设置字体大小
    // 设置每次增减的步长
    lv_spinbox_set_step(spinbox, 1);
    lv_obj_add_event_cb(spinbox, lv_spinbox_change_event_cb, LV_EVENT_VALUE_CHANGED, NULL);     //关联减少事件函数

    int32_t h = lv_obj_get_height(spinbox);
    // 创建增加按钮
    lv_obj_t* btn = lv_button_create(lv_screen_active());    // 创建按钮对象
    lv_obj_set_size(btn, h, h);  // 设置按钮大小为微调框高度的正方形
    lv_obj_align_to(btn, spinbox, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(btn, LV_SYMBOL_PLUS, 0);        // 设置按钮图标
    lv_obj_add_event_cb(btn, lv_spinbox_increment_event_cb, LV_EVENT_LONG_PRESSED_REPEAT, NULL);    //监控连续长按事件
    lv_obj_add_event_cb(btn, lv_spinbox_increment_event_cb, LV_EVENT_SHORT_CLICKED, NULL);          //监控单击事件
    // 创建减少按钮
    btn = lv_button_create(lv_screen_active());   // 创建按钮对象
    lv_obj_set_size(btn, h, h);  // 正方形按钮
    lv_obj_align_to(btn, spinbox, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(btn, LV_SYMBOL_MINUS, 0);       // 设置按钮图标
    lv_obj_add_event_cb(btn, lv_spinbox_decrement_event_cb, LV_EVENT_SHORT_CLICKED, NULL);           //监控单击事件
    lv_obj_add_event_cb(btn, lv_spinbox_decrement_event_cb, LV_EVENT_LONG_PRESSED_REPEAT, NULL);     //监控连续长按事件
#endif
}
int main()
{
    lv_init();

    /*
     * Optional workaround for users who wants UTF-8 console output.
     * If you don't want that behavior can comment them out.
     *
     * Suggested by jinsc123654.
     */
#if LV_TXT_ENC == LV_TXT_ENC_UTF8
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    int32_t zoom_level = 100;
    bool allow_dpi_override = false;
    bool simulator_mode = true;
    lv_display_t* display = lv_windows_create_display(
        L"LVGL Windows Simulator Display 1",
        1080,
        720,
        zoom_level,
        allow_dpi_override,
        simulator_mode);
    if (!display)
    {
        return -1;
    }

    HWND window_handle = lv_windows_get_display_window_handle(display);
    if (!window_handle)
    {
        return -1;
    }

    HICON icon_handle = LoadIconW(
        GetModuleHandleW(NULL),
        MAKEINTRESOURCE(IDI_LVGL_WINDOWS));
    if (icon_handle)
    {
        SendMessageW(
            window_handle,
            WM_SETICON,
            TRUE,
            (LPARAM)icon_handle);
        SendMessageW(
            window_handle,
            WM_SETICON,
            FALSE,
            (LPARAM)icon_handle);
    }

    lv_indev_t* pointer_indev = lv_windows_acquire_pointer_indev(display);
    if (!pointer_indev)
    {
        return -1;
    }

    lv_indev_t* keypad_indev = lv_windows_acquire_keypad_indev(display);
    if (!keypad_indev)
    {
        return -1;
    }

    lv_indev_t* encoder_indev = lv_windows_acquire_encoder_indev(display);
    if (!encoder_indev)
    {
        return -1;
    }

    //lv_demo_widgets();
    
    //lv_demo_benchmark();
    //demo_obj();
    //demo_style();
    //demo_label();
    //demo_label_chinese();
    //demo_img();
    //demo_gif();
    //demo_button();
    //lesson_3_1_1();
    /*lesson_3_2_3();
    lesson_3_3_1();*/
    //lesson_3_3_2();
    //lesson_3_4_4();
    //lesson_3_5_2();
    //lesson_3_6_1();
    /*lesson_3_7_1();*/
    //lesson_3_8_1();
    //lesson_3_9_1();
    //lesson_3_10_1();
    //lesson_3_12_1();
    //lessom_3_13_1();
    lesson_3_14_1();
    while (1)
    {
        uint32_t time_till_next = lv_timer_handler();
        lv_delay_ms(time_till_next);
    }

    return 0;
}
