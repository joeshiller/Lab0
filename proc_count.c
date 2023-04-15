#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>


//This struct is used to create and remove the virtual file
static struct proc_dir_entry *entry;


static int proc_count(struct seq_file *m, void *v){
	struct task_struct *p;
	int process_count = 0;
	for_each_process(p) {
		process_count++;
	}
	seq_printf(m, "%d\n", process_count);	
	return 0;
}

static int __init proc_count_init(void)
{
	entry = proc_create_single("count", 0, NULL, proc_count);
	return 0;
}

static void __exit proc_count_exit(void)
{
	proc_remove(entry);
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Joseph S");
MODULE_DESCRIPTION("Return num of running processes");
MODULE_LICENSE("GPL");
