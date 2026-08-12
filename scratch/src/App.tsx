import * as Blockly from 'blockly';
import { useEffect, useRef } from 'react';
import * as javascriptGenerator from "blockly/javascript";

const moveBlock = {

  type: "robot_move",

  message0: "移动机器人 X %1 Y %2 速度 %3",

  args0: [

    {

      type: "field_number",

      name: "X",

      value: 0,

    },

    {

      type: "field_number",

      name: "Y",

      value: 0,

    },

    {

      type: "field_number",

      name: "SPEED",

      value: 50,

    },

  ],

  previousStatement: null,

  nextStatement: null,

  colour: 120,

};

export default () => {
  const blocklyRef = useRef<HTMLDivElement>(null);
  const workspace = useRef(null);

  const onSave = () => {
    const state = Blockly.serialization.workspaces.save(workspace.current);
    console.log(state);

    const code =
      javascriptGenerator.javascriptGenerator.workspaceToCode(
        workspace.current
      );
    console.log(code);
  }

  useEffect(() => {
    if (!blocklyRef.current) return;
    // init blockly
    Blockly.common.defineBlocksWithJsonArray([
      moveBlock,
    ]);
    // 自定义代码生成
    javascriptGenerator.javascriptGenerator.forBlock["robot_move"] = (block) => {
      const x = block.getFieldValue("X");
      const y = block.getFieldValue("Y");
      const speed = block.getFieldValue("SPEED");
      return `robot.moveTo(${x}, ${y}, ${speed});\n`;
    };
    // 创建工作区
    workspace.current = Blockly.inject(blocklyRef.current, {
      toolbox: {
        kind: "categoryToolbox",
        contents: [
          {
            kind: "category",
            name: "逻辑",
            colour: "#5C81A6",
            contents: [
              {
                kind: "block",
                type: "controls_if",
              },
              {
                kind: "block",
                type: "logic_compare",
              },
            ],

          },

          {

            kind: "category",

            name: "循环",

            colour: "#5CA65C",

            contents: [

              {

                kind: "block",

                type: "controls_repeat_ext",

                inputs: {

                  TIMES: {

                    shadow: {

                      type: "math_number",

                      fields: {

                        NUM: 10,

                      },

                    },

                  },

                },

              },

            ],

          },

          {

            kind: "category",

            name: "数学",

            colour: "#5C68A6",

            contents: [

              {

                kind: "block",

                type: "math_number",

              },

              {

                kind: "block",

                type: "math_arithmetic",

              },

            ],

          },

          // 自定义机器人指令
          {
            kind: "category",
            name: "机器人",
            colour: "#4CAF50",
            contents: [
              {
                kind: "block",
                type: "robot_move",
              },
            ],

          },
        ],

      },
      // 显示缩放按钮
      zoom: {
        controls: true,
        wheel: true,
        startScale: 1,
        maxScale: 3,
        minScale: 0.3,
      },
      // 显示垃圾桶
      trashcan: true,
      // 网格
      grid: {
        spacing: 20,
        length: 3,
        colour: "#ccc",
        snap: true,
      },
    })



    workspace.current.addChangeListener((event) => {

      console.log("事件：", event);

      if (event.type === Blockly.Events.BLOCK_CREATE) {

        console.log("创建了积木");

      }

      if (event.type === Blockly.Events.BLOCK_DELETE) {

        console.log("删除了积木");

      }

      if (event.type === Blockly.Events.BLOCK_MOVE) {

        console.log("移动了积木");

      }

      if (event.type === Blockly.Events.BLOCK_CHANGE) {

        console.log("修改了积木");

      }

    });



    return () => {
      workspace.current.dispose();
    }

  }, [])


  return <div>
    <div
      ref={blocklyRef}
      style={{
        width: "100%",
        height: "600px",
        backgroundColor: "#f0f0f0"
      }}
    ></div>
    <button onClick={onSave}>save</button>
  </div>
}