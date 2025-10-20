int about_us()
{
    
    top_bar();
    //     printf("----------------------------------------\n");
    printf("| About Us \n");
    lines(1);
    color_text(2);
    printf("  Digital Voting System (DVS)\n");
    printf("  developed as a university project\n");

    color_text(0);
    lines(1);
    printf("  Developed by ");
    style_text('b');
    printf("Team 01\n");
    style_text('r');
    lines(1);
    color_text(5);
    printf(" - Hasitha Sandakelum \tTG/2024/2073\n");
    printf(" - Achala Eshan \tTG/2024/2122\n");
    printf(" - Thisagi Omethra \tTG/2024/2075\n");
    printf(" - lakshani Salgadu \tTG/2024/2142\n");
    color_text(0);
    lines(1);
    color_text(6);
    printf("| Our mission is to provide a secure\n");
    printf("| and user-friendly platform for\n");
    printf("| digital voting\n");
    printf("| For more information,\n");
    printf("| visit instructions section.\n");
    color_text(0);  
    lines(3);
    exit_to();
    return 0;
}