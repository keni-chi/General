package com.amazonaws.lambda.demo;

import org.luaj.vm2.Globals;
import org.luaj.vm2.LuaValue;
import org.luaj.vm2.lib.jse.JsePlatform;

import com.amazonaws.services.lambda.runtime.Context;
import com.amazonaws.services.lambda.runtime.RequestHandler;

public class LambdaFunctionHandler implements RequestHandler<Object, String> {

    @Override
    public String handleRequest(Object input, Context context) {
        context.getLogger().log("Input: " + input);

    	Globals globals = JsePlatform.standardGlobals();
    	LuaValue chunk = globals.load("print 'hello, world test'");
    	chunk.call();


        // TODO: implement your handler
        return "Hello from Lambda!";
    }

}
