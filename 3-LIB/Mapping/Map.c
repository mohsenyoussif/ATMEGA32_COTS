sint32 Map(sint32 Copy_sint32InputMIN,sint32 Copy_sint32InputMAX,sint32 Copy_sint32OutputMIN,sint32 Copy_sint32OutputMAX,sint32 Copy_sint32InputVal)
{
    // Ensure no division by zero
    if (Copy_sint32InputMAX == Copy_sint32InputMIN) 
        return Copy_sint32OutputMIN;

    return ((Copy_sint32InputVal - Copy_sint32InputMIN) * (Copy_sint32OutputMAX - Copy_sint32OutputMIN)) / 
           (sint32InputMAX - input_min) + Copy_sint32OutputMIN;
}