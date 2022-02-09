// Reference: https://google.github.io/styleguide/cppguide.html
class ClassName
{
public:
    int class_member_name_;  // with a trailing underscore

    int MethodName(int parameter_name)
    {
        const int kConstantName = 0;  // "k" followed by mixed case
        int local_variable_name = kConstantName;

        return local_variable_name;
    }
};