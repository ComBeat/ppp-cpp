Token t2 = ts.get();
        //Handle Assignment operation
        if (t2.kind == assignment)
        {
            double d = expression();
            set_value(t.name, d);
            return d;
        }